https://github.com/SteveDoyle2/MYSTRAN/blob/op2_plot/dev_docs/post_processing.md


        <div id="readme" class="Box-body readme blob js-code-block-container p-5 p-xl-6 gist-border-0">
    <article class="markdown-body entry-content container-lg" itemprop="text"><h1 dir="auto"><a id="user-content-exporting-results" class="anchor" aria-hidden="true" href="#exporting-results"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Exporting Results</h1>
<p dir="auto">There are a few main ways to export data (to verify):</p>
<table>
<thead>
<tr>
<th>Location</th>
<th>Case Control Command</th>
<th>Notes</th>
</tr>
</thead>
<tbody>
<tr>
<td>F06/ans</td>
<td>DISP=ALL</td>
<td></td>
</tr>
<tr>
<td>F06/ans</td>
<td>DISP(PRINT)=ALL</td>
<td></td>
</tr>
<tr>
<td>OP2</td>
<td>DISP(PLOT)=ALL</td>
<td>partial</td>
</tr>
<tr>
<td>PUNCH</td>
<td>DISP(PUNCH)=ALL</td>
<td></td>
</tr>
<tr>
<td>CSV</td>
<td>DISP(CSV)=ALL</td>
<td>doesn't work</td>
</tr>
<tr>
<td>NEU</td>
<td>DISP(NEU)=ALL</td>
<td>doesn't work</td>
</tr>
</tbody>
</table>
<p dir="auto">The F06 and ANS files are basically the same, so main results support is the same.</p>
<h1 dir="auto"><a id="user-content-op2-plot-support" class="anchor" aria-hidden="true" href="#op2-plot-support"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>OP2 PLOT Support</h1>
<table>
<thead>
<tr>
<th>Command</th>
<th>Support</th>
</tr>
</thead>
<tbody>
<tr>
<td>DISP</td>
<td>True</td>
</tr>
<tr>
<td>ACCEL</td>
<td>True</td>
</tr>
<tr>
<td>OLOAD</td>
<td>True</td>
</tr>
<tr>
<td>SPCFORCE</td>
<td>True</td>
</tr>
<tr>
<td>MPCFORCE</td>
<td>True</td>
</tr>
<tr>
<td>STRESS</td>
<td>False</td>
</tr>
<tr>
<td>STRAIN</td>
<td>False</td>
</tr>
<tr>
<td>FORCE</td>
<td>False</td>
</tr>
<tr>
<td>ESE</td>
<td>N/A</td>
</tr>
<tr>
<td>GPFORCE</td>
<td>N/A</td>
</tr>
</tbody>
</table>
<h1 dir="auto"><a id="user-content-using-sets-with-output-requests" class="anchor" aria-hidden="true" href="#using-sets-with-output-requests"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Using Sets with Output Requests</h1>
<p dir="auto">Q: Does Mystran support sets?  For example:
SET 1 = 1,2,10
DISP(PRINT) = 1
because it supposedly supports
DISP(PRINT) = 1,2,10
which begs the question of is the code compatible with sets, when we do?
SET 1 = 10
DISP(PRINT) = 1</p>
<h2 dir="auto"><a id="user-content-faq" class="anchor" aria-hidden="true" href="#faq"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>FAQ</h2>
<p dir="auto"><strong>Q:</strong> What is the difference between ANS and F06?</p>
<p dir="auto"><strong>A:</strong> ANS is LINK9 (results) only and requires a debug flag to export</p>
<h1 dir="auto"><a id="user-content-op2-params-todo" class="anchor" aria-hidden="true" href="#op2-params-todo"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>OP2 Params (TODO)</h1>
<p dir="auto">PARAM,POST,-1</p>
<ul dir="auto">
<li>current: activates the NEU output?</li>
<li>new: activates op2 output</li>
<li>default=0 (consistent with Nastran) -&gt; no op2???  PLOT does nothing?</li>
</ul>
<p dir="auto">PARAM,OGEOM,YES</p>
<ul dir="auto">
<li>current: doesn't exist (NO)</li>
<li>new: YES=activates op2 geometry writing; NO=no geometry</li>
<li>default=YES (consistent with Nastran)</li>
</ul>
<h1 dir="auto"><a id="user-content-static-post-processing-support" class="anchor" aria-hidden="true" href="#static-post-processing-support"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Static Post-Processing Support</h1>
<p dir="auto">see <a class="issue-link js-issue-link" data-error-text="Failed to load title" data-id="995396451" data-permission-text="Title is private" data-url="https://github.com/dr-bill-c/MYSTRAN/issues/24" data-hovercard-type="pull_request" data-hovercard-url="/dr-bill-c/MYSTRAN/pull/24/hovercard" href="https://github.com/dr-bill-c/MYSTRAN/pull/24#event-5702809912">dr-bill-c#24 (comment)</a></p>
<table>
<thead>
<tr>
<th>Result</th>
<th>F06</th>
<th>OP2</th>
<th>PCH</th>
<th>CSV</th>
<th>Notes</th>
</tr>
</thead>
<tbody>
<tr>
<td>Displacement</td>
<td>Yes</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>SPC Force</td>
<td>Yes</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>MPC Force</td>
<td>Yes</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>Applied Load Vector</td>
<td>Yes</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>Grid Point Weight</td>
<td>Yes</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td>See Grid Point Weight note</td>
</tr>
<tr>
<td>Grid Point Force</td>
<td>Yes</td>
<td>No</td>
<td>???</td>
<td>No</td>
<td>F06 writing is coupled with data structure and limits OP2 integration; should be refactored</td>
</tr>
</tbody>
</table>
<table>
<thead>
<tr>
<th>Force Result</th>
<th>F06</th>
<th>OP2</th>
<th>PCH</th>
<th>CSV</th>
<th>Notes</th>
</tr>
</thead>
<tbody>
<tr>
<td>CELASx</td>
<td>???</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CROD</td>
<td>Yes</td>
<td>No</td>
<td>???</td>
<td>No</td>
<td>OP2 code written; commented out due to bug</td>
</tr>
<tr>
<td>CBUSH</td>
<td>???</td>
<td>???</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CBAR</td>
<td>???</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CBEAM</td>
<td>???</td>
<td>No</td>
<td>???</td>
<td>No</td>
<td>large difference between output structure of Nastran &amp; Mystran</td>
</tr>
<tr>
<td>CSHEAR</td>
<td>???</td>
<td>???</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CTRIA3</td>
<td>???</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CQUAD4 Iso-Center</td>
<td>???</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CQUAD4 Iso-Corner</td>
<td>???</td>
<td>No</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CTRIA3 Comp</td>
<td>???</td>
<td>No</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CQUAD4 Comp</td>
<td>???</td>
<td>No</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>Solid</td>
<td>N/A</td>
<td>N/A</td>
<td>N/A</td>
<td>N/A</td>
<td>No outputs available; expected</td>
</tr>
</tbody>
</table>
<table>
<thead>
<tr>
<th>Stress Result</th>
<th>F06</th>
<th>OP2</th>
<th>PCH</th>
<th>CSV</th>
<th>Notes</th>
</tr>
</thead>
<tbody>
<tr>
<td>CELASx</td>
<td>???</td>
<td>???</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CROD</td>
<td>Yes</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td>no axial/torsion margin</td>
</tr>
<tr>
<td>CBUSH</td>
<td>???</td>
<td>???</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CBAR</td>
<td>???</td>
<td>???</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CBEAM</td>
<td>???</td>
<td>???</td>
<td>???</td>
<td>No</td>
<td>large difference between output structure of Nastran &amp; Mystran</td>
</tr>
<tr>
<td>CSHEAR</td>
<td>???</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CTRIA3 Iso</td>
<td>???</td>
<td>???</td>
<td>???</td>
<td>No</td>
<td>OP2 plane1/2 results faked; no FIBER/CURV support (FIBER only); no MAXS/MISES support (MISES only)</td>
</tr>
<tr>
<td>CQUAD4 Iso-Center</td>
<td>???</td>
<td>???</td>
<td>???</td>
<td>No</td>
<td>OP2 plane1/2 results faked; no FIBER/CURV support (FIBER only); no MAXS/MISES support (MISES only)</td>
</tr>
<tr>
<td>CQUAD4 Iso-Corner</td>
<td>???</td>
<td>???</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CTRIA3 Comp</td>
<td>???</td>
<td>???</td>
<td>???</td>
<td>No</td>
<td>no FIBER/CURV support (FIBER only); no MAXS/MISES support (MISES only)</td>
</tr>
<tr>
<td>CQUAD4 Comp</td>
<td>???</td>
<td>???</td>
<td>???</td>
<td>No</td>
<td>no FIBER/CURV support (FIBER only); no MAXS/MISES support (MISES only)</td>
</tr>
<tr>
<td>Solid</td>
<td>Yes</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td>No directional vectors; No coordinate system support; no transform support</td>
</tr>
</tbody>
</table>
<table>
<thead>
<tr>
<th>Strain Result</th>
<th>F06</th>
<th>OP2</th>
<th>PCH</th>
<th>CSV</th>
<th>Notes</th>
</tr>
</thead>
<tbody>
<tr>
<td>CELASx</td>
<td>???</td>
<td>???</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CROD</td>
<td>Yes</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td>no axial/torsion margin</td>
</tr>
<tr>
<td>CBUSH</td>
<td>???</td>
<td>???</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CBAR</td>
<td>???</td>
<td>???</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CBEAM</td>
<td>???</td>
<td>???</td>
<td>???</td>
<td>No</td>
<td>results not calculated</td>
</tr>
<tr>
<td>CTRIA3 Iso</td>
<td>???</td>
<td>???</td>
<td>???</td>
<td>No</td>
<td>OP2 plane1/2 results faked; no FIBER/CURV support (FIBER only); no MAXS/MISES support (MISES only)</td>
</tr>
<tr>
<td>CQUAD4 Iso-Center</td>
<td>???</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td>OP2 plane1/2 results faked; no FIBER/CURV support (FIBER only); no MAXS/MISES support (MISES only)</td>
</tr>
<tr>
<td>CQUAD4 Iso-Corner</td>
<td>???</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td>OP2 plane1/2 results faked; no FIBER/CURV support (FIBER only); no MAXS/MISES support (MISES only)</td>
</tr>
<tr>
<td>CTRIA3 Comp</td>
<td>???</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td>no FIBER/CURV support (FIBER only); no MAXS/MISES support (MISES only)</td>
</tr>
<tr>
<td>CQUAD4 Comp</td>
<td>???</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td>no FIBER/CURV support (FIBER only); no MAXS/MISES support (MISES only)</td>
</tr>
<tr>
<td>Solid</td>
<td>Yes</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td>No directional vectors; No coordinate system support; no transform support</td>
</tr>
</tbody>
</table>
<table>
<thead>
<tr>
<th>Strain Energy Result</th>
<th>F06</th>
<th>OP2</th>
<th>PCH</th>
<th>CSV</th>
<th>Notes</th>
</tr>
</thead>
<tbody>
<tr>
<td>CELASx</td>
<td>???</td>
<td>No</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CROD</td>
<td>???</td>
<td>No</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CBUSH</td>
<td>???</td>
<td>No</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CBAR</td>
<td>???</td>
<td>No</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CBEAM</td>
<td>???</td>
<td>No</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CTRIA3 Iso</td>
<td>???</td>
<td>No</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CQUAD4 Iso-Center</td>
<td>???</td>
<td>No</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CQUAD4 Iso-Corner</td>
<td>???</td>
<td>No</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CTRIA3 Comp</td>
<td>???</td>
<td>No</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>CQUAD4 Comp</td>
<td>???</td>
<td>No</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>Solid</td>
<td>???</td>
<td>No</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
</tbody>
</table>
<h1 dir="auto"><a id="user-content-eigen-post-processing-support" class="anchor" aria-hidden="true" href="#eigen-post-processing-support"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Eigen Post-Processing Support</h1>
<table>
<thead>
<tr>
<th>Result</th>
<th>F06</th>
<th>ANS</th>
<th>OP2</th>
<th>PCH</th>
<th>CSV</th>
<th>Notes</th>
</tr>
</thead>
<tbody>
<tr>
<td>Grid Point Weight</td>
<td>Yes</td>
<td>???</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>Eigenvector</td>
<td>Yes</td>
<td>???</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>Eigenvalue</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
<tr>
<td>MEFFMASS</td>
<td>Yes</td>
<td>???</td>
<td>No</td>
<td>???</td>
<td>No</td>
<td></td>
</tr>
</tbody>
</table>
<h1 dir="auto"><a id="user-content-notes" class="anchor" aria-hidden="true" href="#notes"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Notes</h1>
<h2 dir="auto"><a id="user-content-grid-point-weight-limitation" class="anchor" aria-hidden="true" href="#grid-point-weight-limitation"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>Grid Point Weight Limitation</h2>
<p dir="auto">! Generate total mass, first and second moments by summing up mass terms.
! XD(i) are components of vector from ref point to a mass point.
! At this time, mass units are input units without PARAM WTMASS,
! which is what we want for the grid point weight generator.
! Later the mass will be converted by multiplying by WTMASS.</p>
<ul dir="auto">
<li>mass should be (3,1) instead of (1,)</li>
<li>CG should be (3,3) instead of (3,1)</li>
<li>applies to all outputs</li>
</ul>
<h2 dir="auto"><a id="user-content-ansf06-limitations" class="anchor" aria-hidden="true" href="#ansf06-limitations"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>ANS/F06 Limitations</h2>
<h2 dir="auto"><a id="user-content-op2-limitations" class="anchor" aria-hidden="true" href="#op2-limitations"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>OP2 Limitations</h2>
<ul dir="auto">
<li>No FIBER/CURV support (FIBER only)</li>
<li>No MAXS/MISES support (MISES only)</li>
<li>No margin support</li>
</ul>
<h2 dir="auto"><a id="user-content-pch-limitations" class="anchor" aria-hidden="true" href="#pch-limitations"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>PCH Limitations</h2>
<h2 dir="auto"><a id="user-content-op2-specific-notes" class="anchor" aria-hidden="true" href="#op2-specific-notes"><svg class="octicon octicon-link" viewBox="0 0 16 16" version="1.1" width="16" height="16" aria-hidden="true"><path fill-rule="evenodd" d="M7.775 3.275a.75.75 0 001.06 1.06l1.25-1.25a2 2 0 112.83 2.83l-2.5 2.5a2 2 0 01-2.83 0 .75.75 0 00-1.06 1.06 3.5 3.5 0 004.95 0l2.5-2.5a3.5 3.5 0 00-4.95-4.95l-1.25 1.25zm-4.69 9.64a2 2 0 010-2.83l2.5-2.5a2 2 0 012.83 0 .75.75 0 001.06-1.06 3.5 3.5 0 00-4.95 0l-2.5 2.5a3.5 3.5 0 004.95 4.95l1.25-1.25a.75.75 0 00-1.06-1.06l-1.25 1.25a2 2 0 01-2.83 0z"></path></svg></a>OP2 specific notes</h2>
<ol dir="auto">
<li>OP2 follows the roughly MSC 2005r2-2010 output format, which uses the
XXXXXXXX version code</li>
<li>At that time, the output for Mystran compatible results were nearly the
same between MSC and NX/Simcenter.  Since then, it has diverged</li>
</ol>
</article>
  </div>

    </div>

  </readme-toc>

  

  <details class="details-reset details-overlay details-overlay-dark" id="jumpto-line-details-dialog">
    <summary data-hotkey="l" aria-label="Jump to line"></summary>
    <details-dialog class="Box Box--overlay d-flex flex-column anim-fade-in fast linejump" aria-label="Jump to line">
      <!-- '"` --><!-- </textarea></xmp> --></option></form><form class="js-jump-to-line-form Box-body d-flex" data-turbo="false" action="" accept-charset="UTF-8" method="get">
        <input class="form-control flex-auto mr-3 linejump-input js-jump-to-line-field" type="text" placeholder="Jump to line&hellip;" aria-label="Jump to line" autofocus>
          <button data-close-dialog="" type="submit" data-view-component="true" class="btn">    Go
</button>
</form>    </details-dialog>
  </details>


</div>

  </div>


  </div>

  </turbo-frame>


    </main>
  </div>

  </div>

