# Manual for `f06csv`

###### by Bruno Borges Paschoalinoto, for version `0.3.5` (2024-01-28)

This document gives a thorough outline of the capabilities of the `f06csv`
utility.


## 1. Basic information about `f06csv`

### 1.1. What is it?

Put simply, it's meant to convert from the F06 format, the human-readable text
output produced by Nastran-like FEM solvers (e.g. NX/Simcenter Nastran,
MYSTRAN, Autodesk Inventor Nastran, MSC Nastran, NASTRAN-95, etc.) into a
well-organised, fixed-with table format -- a CSV (comma-separated values) file.

Discussed use cases for such a tool include but are not limited to:

  - Loading output data into spreadsheets for analysis (manual or automated),
  - Comparing data produced by different solvers by translating results into
  a common format, and
  - Future-proofing against dependency on software needed to work with
  proprietary and/or closed formats.

It's a work-in-progress, and part of a larger project.

### 1.2. Who made it and what for?

Not only `f06csv`, but this entire repository has been motivated, guided and
funded by the [MYSTRAN](https://mystran.com) project. The primary author is
[Bruno Borges Paschoalinoto](https://bor.gs/en).

We already have an automated verification suite for MYSTRAN, but it was based
on extracting data from MYSTRAN F06 files in a very specific way. With this
toolset, we can work with F06 files generated from other solvers, and without
having to modify our code every time some blocks change order.

Another advantage is that, by working with two human-readable formats,
double-checking and looking for bugs in the tool is quite easy. Debugging
binary formats usually requires other tools, which might have bugs themselves.
With two text formats, we cut through all that!

### 1.3. Can I contribute? What's the license?

Contributions are welcome! Not just code -- you can report bugs, and request
features. It's not trivial to figure out what engineers want -- I'm just a
programmer. Tell us what blocks you want to see supported, send us F06 files
to work with, maybe even help us implement support for more solvers!

As for licensing, all of the code and examples are published under the
Unlicense. That means, in most juristictions, *public domain*. Whatever
contributions you post are released under the Unlicense -- no exceptions, no
take-backsies.

This being public domain, I can't enforce any requests... but I kindly ask
that, should you use this tool at work, integrate it into a larger project,
link against the library to use it in an important way, *et cetera*, please do
give credit to the author(s) and the MYSTRAN project/community. You're not
*required* to, but I trust a good developer to find this request pretty darn
reasonable.

## 2. Tool overview

### 2.1. How does `f06csv` work, in a nutshell?

It's a two-step process. First, it uses the `f06` library (part of this
repository) to parse an F06 file into abstract data structures -- mainly its
"data blocks" (more on that later). Then, it uses the `nas_csv` library (also
in this repository) to turn these abstract data structures into CSV records.
It then filters/formats these records acoording to the user's specifications,
and outputs them to either a file or standard output (your terminal).

### 2.2. Care to go into a bit more detail?

Both these processes are all about *blocks*. Blocks, put simply, are the
chunks of data announced by the big ol' spaced letters, like
`D I S P L A C E M E N T S`. We call those "headers" for the sake of
professionalism. The `f06` library has a parser, it looks for these headers,
and when it sees a *supported* block, it engages a decoder for that specific
block. After all, they all have different kinds of data, laid out in different
ways across solvers.

Oh, yeah, the parser also looks for meta-information such as subcase, warnings,
fatal errors, the solver, and (soon) the solution type. Block decoders use
these metadata to make decisions on how to parse each line that comes after the
header.

Once all that's done, blocks are tidied up, merged (some solvers have this
"paging" thing where they break up blocks of the same type -- we recommend you
turn it **off**), and we're ready for the next step.

First off, we output (if requested) the zeroth block, containing general
information about the input file and the solution.

Now, the blocks are passed to "block converters". These take F06 blocks and
output CSV records made up of a CSV block identifier (CSV blocks are not the
same as F06 blocks; for instance, the "stresses" block contains the data from
all the different stress blocks in the F06), followed by ten records. Their
meaning can be better understood by turning on the headers with `--headers`
(shorthand: `-H`).

The resulting CSV records are filtered and formatted based on options which we
are gonna discuss later, and then they go to either a file or standard output,
which is usually your terminal screen unless you redirect it somewhere with
`>`/`>>`. That's it.

## 3. Command-line options

### 3.1. Options' format

So it's all about these options. Before we discuss them, we need to talk about
how they're formatted. If you're familiar with the Unix/`stdarg` way of doing
things -- you know, single dashes for short flags, double dashes for long-form,
quotes processed only by the shell -- you can skip this section. Otherwise,
keep on reading.

#### 3.1.1. Types of options

Once your command is broken up into a list of strings, that list of strings is
processed according to some rules. Before we discuss these rules, let's discuss
the *types* of options the program takes. An option has three basic properties:

  - Does it have a name (long? short?) or is it positional?
  - Is it required? (currently, only the input file is required)
  - Does it take a value? If so, what kind of value?

Here's some examples:

  - input file: positional, required, file path
  - headers: named (`headers` or `H`), optional, no value
  - CSV block IDs: named (`blocks` or `b`), optional, comma-separated names or
    numbers

Now we know how to discuss options, let's see how each type of option is
passed.

#### 3.1.2. Positional options

There's just one positional option: the input file. It's required. If you want
the program to read from standard input, pass a `-`. Since this argument is
taken by position, it can be anywhere in the command as long as long as there
is no ambiguity. When in doubt, leave it at the end of the command. I'll
discuss ambiguity later on.

#### 3.1.3. Named options

Options with names can have a short (single-character) name, a long name, or
both. Short names require a single dash (`-`) behind them, long names take two.

For instance, the option to generate headers has both a long name, `headers`,
and a short one, `H`. So, if you want to tell the program to generate headers,
you can choose to add either `--headers` or `-H` to the command.

When they take values, you can choose how to separate the name from the value:

  - Short names: no separation, an equals sign, or whitespace
  - Long names: an equals sign, or whitespace.

One exception:
**don't use whitespace when the argument is a comma-separated list.**
If you really hate commas that much, you can pass list options multiple times,
and they'll get "appended".

Better yet: **when in doubt, use an equals sign.**

For instance, if you want to generate CSV blocks 0 to 3, all the following will
work:

  - `-b=0,1,2,3`
  - `-b1,2,3`
  - `--blocks=0,1,2,3`
  - `-b0 -b1 -b2 -b3`
  - `-b0,1 -b2,3` (weirdo)

The following will NOT work:

  - `-b 0,1,2,3`
  - `--blocks 0,1,2,3`
  - `--blocks0,1,2,3`

Another example: suppose you want the CSV delimiter to be a space. All the
following will work:

  - `-d " "`
  - `-d=" "`
  - `-d" "`
  - `--delim=" "`
  - `--delim " "`

All of that would work with `'` instead of `"`.

#### 3.1.4. Fusing short-form options

Ever done `ls -la` on Linux? Yeah, it's the same as `ls -l -a`. That's the
power of short-form options: they can be fused. Of course, that means only the
last one can take a value. For instance `-b0,1,2 -H` can be `-Hb0,1,2`.

The next section will explain how spaces and quotes are parsed, and how all of
that figures into the processing of list options. Listen, it's a lot, so let's
make a deal: follow the rules, don't ask about *the sole exception*, and you
can skip it. Deal?

#### 3.1.5. Spaces, quotes, commas and lists

**This section is not needed to use the program if you are willing to stick
to the rules on the previous two sections. Feel free to skip it.**

This is one of these things that programmers know by heart and users know by
intuition, but it's best we clear it up before going any further. All programs,
when invoked, get a list of text strings. The actual mechanism behind this is
both complicated and immaterial; for now, you just have to know it's your
*shell* that does it. Take "shell" to mean "the program that interprets your
commands" here -- `cmd.exe` or PowerShell on Windows, `bash` or `zsh` on Linux.

All modern shells set that list of strings (the argument vector) more or less
the same way. The zeroth string is always the program name or path, the other
ones follow the same general rules:

  1. Whitespace separates arguments.
  2. Quotes (single or double) allow arguments with whitespace.
  3. Other "special" characters can do stuff (shell-specific).
  4. These special characters can be escaped (usually with a `\`).

Once the program gets this list of strings, then it can do its own processing,
parsing, validation, etc. But quotes and spaces and environment variables? All
that happens before the program even runs.

So there are two layers of processing going on: first, the shell processes the
command into a list of strings, and then the `clap` library parses them into
high-level option values for me. Let's illustrate this with some examples, all
for setting the CSV delimiter to a single space.

| What you type | What turns up in `argv` |
|---------------|-------------------------|
| `-d" "`       | `-d `                   |
| `-d\ `        | `-d `                   |
| `-d=" "`      | `-d= `                  |
| `-d " "`      | `-d`, ` `               |

Okay, so how do list options work?

| What you type | What turns up in `argv` | Works?  |
|---------------|-------------------------|---------|
| `-b0,1,2`     | `-b0,1,2`               | Yes     |
| `-b"0,1,2"`   | `-b0,1,2`               | Yes     |
| `-b=0,1,2`    | `-b=0,1,2`              | Yes     |
| `-b 0,1,2`    | `-b`, `0,1,2`           | No      |
| `-b "0,1,2"`  | `-b`, `0,1,2`           | No      |
| `-b "0 1 2"`  | `-b`, `0 1 2`           | No      |
| `-b 0 1 2`    | `-b`, `0`, `1`, `2`     | *Maybe* |

As you can see, list options are usualy *not* broken up by the shell: the whole
string `0,1,2` turns up in the argument vector and *then* `clap` breaks it up
and interprets it as CSV block IDs.

The first question an astute reader might ask is: "both `-d" "` and `-d " "`
work, so why does `-b0,1,2` work but not `-b 0,1,2`?

That's to do with the steps of the process. So far, you know it's goes like
this: first the shell breaks the command into a list of strings, and then a
library within the program does the rest. Okay, but what if the argument itself
is a list? Well, then it's all a matter of **who breaks it up**.

For instance, when you pass `-b0,1,2`, it's the library doing the breaking-up.
It's set up to use commas for that. All fine and dandy.

But when you pass `-b 0,1,2`, first the shell breaks it up, then the library?
That won't do. **One of them has to do all the breaking-up of the list.**

That's why `-b 0 1 2` *can* work. See, since it's not the library doing the
breaking-up, it's the shell. So, the library, while going through the list of
strings provided by the shell, has to decide when to *stop*. I didn't set a
"sentinel" value or anything, so there are three ways it can stop:

  1. The command ends right there;
  2. Another named argument is found: `-b 0 1 2 -H`;
  3. You pass a `--`, a non-argument that says "everything from here on out is
  to be interpreted as a positional argument": `-b 0 1 2 -- input.f06`.

See, if you just do `f06csv -b 0 1 2 input.f06`, the library will try to
interpret `input.f06` as a CSV block ID/name. Sounds stupid, but programs
operate on rules, not implied meaning. What if you had a file named
`displacements` or `3`? You can! It's all about rules.

This explains the "sole exception" I mentioned earlier ("if the option takes
a list of things, don't separate it from its name using whitespace").
It's handy shorthand for "*if the option takes a list of things, you can
separate it from its name using whitespace, but that'll cause it to be broken
up by the shell and not the library, therefore you'll need to use spaces
instead of commas, and also signal its ending to avoid ambiguity with a
positional argument, namely the input file name.*"

Phew! Should've taken my deal.

### 3.2. The options themselves

Now that you know how to properly type out all kinds of options in the command
line, I can show you what each one does in detail. If you're in a hurry, just
do `--help` (or `-h`).

#### 3.2.1. General output and formatting

##### 3.2.1.1. `--headers` (`-H`)

Takes no value. When present, this will cause the program to generate headers.
These are not for the overall CSV -- they are output each time the columns
change meaning! For example, in a stress block, a header row will show up every
time the element type changes.

However, the program always groups rows with the same header together. This
ensures the same header is never written more than once.

##### 3.2.1.2. `-o <output file>`

Takes a file path. Output will be written to that file instead of standard
output, which is the default. You can always use your shell to achieve the
exact same result via the `>` (write) and `>>` (append) operators.

##### 3.2.1.3. `--delim <char>` (`-d <char>`)

Takes a single character, which will be used as the CSV field delimiter. When
not supplied, a comma is used.

##### 3.2.1.4. `--crlf`

This flag ensures the line break used is CR+LF (Windows). Only enable it if you
have trouble with line breaks on Windows, especially on terminals.

##### 3.2.1.5. `--blanks <fill>` (`-B <fill>`)

This defines what to put in fields corresponding to unused columns. It can be
one of these:

  - `zero`: blank fields will contain a single `0`.
  - `space`: blank fields will contain a single space.
  - `dash`: blank fields will contain a single dash (`-`).
  - `dashes` (default): blank fields will contain five dashes (`-----`).
  - `empty`: blank fields will contain literally nothing.

##### 3.2.1.6. `--align <align>`

This option will make columns line up by putting spaces around values with
below-maximal width. It can be `left`, `right`, or `center` (aligning values to
these sides of the column) or `none` (default behaviour, no alignment).

*Note: this might have a runtime impact, since the whole file has to be
computed twice. The first run (to determine column widths) is much faster
since no records are stored or saved, so it's far from a doubling. Still, keep
this in mind when working with very large files.*

#### 3.2.2. Number formatting options

##### 3.2.2.1. `--decimals <places>`

Takes a non-negative integer (default: `6`). This sets the number of decimal
places to use when printing floating-point numbers (real numbers).

##### 3.2.2.2. `--no-sci`

When set, this flag causes real numbers to be printed in "pure" decimal form
(as opposed to scientific notation, the default).

##### 3.2.2.3. `--omit-plus`

When set, this flag will omit the redundant `+` prefixing non-negative reals.

##### 3.2.2.4. `--small-e`

When set, this flag will make a lower-case `e` to be used when printing numbers
in scientific notation. Obviously, this has no effect when `--no-sci` is set.

#### 3.2.3. Filters

All currently-implemented filters are based on *output*, not input. They all
operate on a property of a record. When the record has this property, it'll
only be written if the property matches the allowed values. Filters are *lax*,
meaning records without the property won't be affected.

Also, they take lists of values. Make sure you're familiar with the formatting
we discussed a while ago. Filters do **not** affect the order of records, only
which ones get thrown out.

##### 3.2.3.1. `--gids=gid1,gid2,gid3,...,gidN` (`-g=gid1,gid2,gid3,...,gidN`)

This filters by **grid point ID**. Each GID must be a non-negative integer.

##### 3.2.3.2. `--eids=eid1,eid2,eid3,...,eidN` (`-e=eid1,eid2,eid3,...,eidN`)

This filters by **element ID**. Each EID must be a non-negative integer.

##### 3.2.3.3. `--etypes=t1,t2,t3,...,tN` (`-t=t1,t2,t3,...,tN`)

This filters by **element type**. Each type is an upper-case element name,
*without a leading C*, e.g. `QUAD4`, **not** `CQUAD4`.

##### 3.2.3.4. `--subcases=s1,s2,s3,...,sN` (`-s=s1,s2,s3,...,sN`)

This filters by **subcase number**. Each must be a non-negative integer.

##### 3.2.3.5. `--blocks=b1,b2,b3,...,bN` (`-b=b1,b2,b3,...,bN`)

This filters by **CSV block**, the thing that determines the first number on
each record. It can take abbreviated names (`meta`, `disp`, `stress`, etc.) or
the block numbers themselves.

#### 3.2.4. Help

There are two help commands: `-h` and `--help`. It't the **only** instance of
a short name producing different behaviour, and that's entirely on the `clap`
library, not me.

*Both `-h` and `--help` list all options and flags.* The only difference is
that `-h` prints one parameter per line (by only printing the first line of
each option's description) whereas `--help` prints the whole description.

Use `-h` when you just need a refresher for the flags's names (e.g. you see
`-t` in an example and forgot what it does), and `--help` when you need their
full descriptions without having to refer to this manual every time.

## 4. Examples
