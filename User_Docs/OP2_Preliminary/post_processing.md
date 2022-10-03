https://github.com/SteveDoyle2/MYSTRAN/tree/op2_plot/dev_docs

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

          <footer class="footer width-full container-xl p-responsive">
  <h2 class='sr-only'>Footer</h2>

  <div class="position-relative d-flex flex-items-center pb-2 f6 color-fg-muted border-top color-border-muted flex-column-reverse flex-lg-row flex-wrap flex-lg-nowrap mt-6 pt-6">
    <div class="list-style-none d-flex flex-wrap col-0 col-lg-2 flex-justify-start flex-lg-justify-between mb-2 mb-lg-0">
      <div class="mt-2 mt-lg-0 d-flex flex-items-center">
        <a aria-label="Homepage" title="GitHub" class="footer-octicon mr-2" href="https://github.com">
          <svg aria-hidden="true" height="24" viewBox="0 0 16 16" version="1.1" width="24" data-view-component="true" class="octicon octicon-mark-github">
    <path fill-rule="evenodd" d="M8 0C3.58 0 0 3.58 0 8c0 3.54 2.29 6.53 5.47 7.59.4.07.55-.17.55-.38 0-.19-.01-.82-.01-1.49-2.01.37-2.53-.49-2.69-.94-.09-.23-.48-.94-.82-1.13-.28-.15-.68-.52-.01-.53.63-.01 1.08.58 1.23.82.72 1.21 1.87.87 2.33.66.07-.52.28-.87.51-1.07-1.78-.2-3.64-.89-3.64-3.95 0-.87.31-1.59.82-2.15-.08-.2-.36-1.02.08-2.12 0 0 .67-.21 2.2.82.64-.18 1.32-.27 2-.27.68 0 1.36.09 2 .27 1.53-1.04 2.2-.82 2.2-.82.44 1.1.16 1.92.08 2.12.51.56.82 1.27.82 2.15 0 3.07-1.87 3.75-3.65 3.95.29.25.54.73.54 1.48 0 1.07-.01 1.93-.01 2.2 0 .21.15.46.55.38A8.013 8.013 0 0016 8c0-4.42-3.58-8-8-8z"></path>
</svg>
</a>        <span>
        &copy; 2022 GitHub, Inc.
        </span>
      </div>
    </div>

    <nav aria-label='footer' class="col-12 col-lg-8">
      <h3 class='sr-only' id='sr-footer-heading'>Footer navigation</h3>
      <ul class="list-style-none d-flex flex-wrap col-12 flex-justify-center flex-lg-justify-between mb-2 mb-lg-0" aria-labelledby='sr-footer-heading'>
          <li class="mr-3 mr-lg-0"><a href="https://docs.github.com/en/github/site-policy/github-terms-of-service" data-analytics-event="{&quot;category&quot;:&quot;Footer&quot;,&quot;action&quot;:&quot;go to terms&quot;,&quot;label&quot;:&quot;text:terms&quot;}">Terms</a></li>
          <li class="mr-3 mr-lg-0"><a href="https://docs.github.com/en/github/site-policy/github-privacy-statement" data-analytics-event="{&quot;category&quot;:&quot;Footer&quot;,&quot;action&quot;:&quot;go to privacy&quot;,&quot;label&quot;:&quot;text:privacy&quot;}">Privacy</a></li>
          <li class="mr-3 mr-lg-0"><a data-analytics-event="{&quot;category&quot;:&quot;Footer&quot;,&quot;action&quot;:&quot;go to security&quot;,&quot;label&quot;:&quot;text:security&quot;}" href="https://github.com/security">Security</a></li>
          <li class="mr-3 mr-lg-0"><a href="https://www.githubstatus.com/" data-analytics-event="{&quot;category&quot;:&quot;Footer&quot;,&quot;action&quot;:&quot;go to status&quot;,&quot;label&quot;:&quot;text:status&quot;}">Status</a></li>
          <li class="mr-3 mr-lg-0"><a data-ga-click="Footer, go to help, text:Docs" href="https://docs.github.com">Docs</a></li>
          <li class="mr-3 mr-lg-0"><a href="https://support.github.com?tags=dotcom-footer" data-analytics-event="{&quot;category&quot;:&quot;Footer&quot;,&quot;action&quot;:&quot;go to contact&quot;,&quot;label&quot;:&quot;text:contact&quot;}">Contact GitHub</a></li>
          <li class="mr-3 mr-lg-0"><a href="https://github.com/pricing" data-analytics-event="{&quot;category&quot;:&quot;Footer&quot;,&quot;action&quot;:&quot;go to Pricing&quot;,&quot;label&quot;:&quot;text:Pricing&quot;}">Pricing</a></li>
        <li class="mr-3 mr-lg-0"><a href="https://docs.github.com" data-analytics-event="{&quot;category&quot;:&quot;Footer&quot;,&quot;action&quot;:&quot;go to api&quot;,&quot;label&quot;:&quot;text:api&quot;}">API</a></li>
        <li class="mr-3 mr-lg-0"><a href="https://services.github.com" data-analytics-event="{&quot;category&quot;:&quot;Footer&quot;,&quot;action&quot;:&quot;go to training&quot;,&quot;label&quot;:&quot;text:training&quot;}">Training</a></li>
          <li class="mr-3 mr-lg-0"><a href="https://github.blog" data-analytics-event="{&quot;category&quot;:&quot;Footer&quot;,&quot;action&quot;:&quot;go to blog&quot;,&quot;label&quot;:&quot;text:blog&quot;}">Blog</a></li>
          <li><a data-ga-click="Footer, go to about, text:about" href="https://github.com/about">About</a></li>
      </ul>
    </nav>
  </div>

  <div class="d-flex flex-justify-center pb-6">
    <span class="f6 color-fg-muted"></span>
  </div>
</footer>




  <div id="ajax-error-message" class="ajax-error-message flash flash-error" hidden>
    <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-alert">
    <path fill-rule="evenodd" d="M8.22 1.754a.25.25 0 00-.44 0L1.698 13.132a.25.25 0 00.22.368h12.164a.25.25 0 00.22-.368L8.22 1.754zm-1.763-.707c.659-1.234 2.427-1.234 3.086 0l6.082 11.378A1.75 1.75 0 0114.082 15H1.918a1.75 1.75 0 01-1.543-2.575L6.457 1.047zM9 11a1 1 0 11-2 0 1 1 0 012 0zm-.25-5.25a.75.75 0 00-1.5 0v2.5a.75.75 0 001.5 0v-2.5z"></path>
</svg>
    <button type="button" class="flash-close js-ajax-error-dismiss" aria-label="Dismiss error">
      <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-x">
    <path fill-rule="evenodd" d="M3.72 3.72a.75.75 0 011.06 0L8 6.94l3.22-3.22a.75.75 0 111.06 1.06L9.06 8l3.22 3.22a.75.75 0 11-1.06 1.06L8 9.06l-3.22 3.22a.75.75 0 01-1.06-1.06L6.94 8 3.72 4.78a.75.75 0 010-1.06z"></path>
</svg>
    </button>
    You can’t perform that action at this time.
  </div>

  <div class="js-stale-session-flash flash flash-warn flash-banner" hidden
    >
    <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-alert">
    <path fill-rule="evenodd" d="M8.22 1.754a.25.25 0 00-.44 0L1.698 13.132a.25.25 0 00.22.368h12.164a.25.25 0 00.22-.368L8.22 1.754zm-1.763-.707c.659-1.234 2.427-1.234 3.086 0l6.082 11.378A1.75 1.75 0 0114.082 15H1.918a1.75 1.75 0 01-1.543-2.575L6.457 1.047zM9 11a1 1 0 11-2 0 1 1 0 012 0zm-.25-5.25a.75.75 0 00-1.5 0v2.5a.75.75 0 001.5 0v-2.5z"></path>
</svg>
    <span class="js-stale-session-flash-signed-in" hidden>You signed in with another tab or window. <a href="">Reload</a> to refresh your session.</span>
    <span class="js-stale-session-flash-signed-out" hidden>You signed out in another tab or window. <a href="">Reload</a> to refresh your session.</span>
  </div>
    <template id="site-details-dialog">
  <details class="details-reset details-overlay details-overlay-dark lh-default color-fg-default hx_rsm" open>
    <summary role="button" aria-label="Close dialog"></summary>
    <details-dialog class="Box Box--overlay d-flex flex-column anim-fade-in fast hx_rsm-dialog hx_rsm-modal">
      <button class="Box-btn-octicon m-0 btn-octicon position-absolute right-0 top-0" type="button" aria-label="Close dialog" data-close-dialog>
        <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-x">
    <path fill-rule="evenodd" d="M3.72 3.72a.75.75 0 011.06 0L8 6.94l3.22-3.22a.75.75 0 111.06 1.06L9.06 8l3.22 3.22a.75.75 0 11-1.06 1.06L8 9.06l-3.22 3.22a.75.75 0 01-1.06-1.06L6.94 8 3.72 4.78a.75.75 0 010-1.06z"></path>
</svg>
      </button>
      <div class="octocat-spinner my-6 js-details-dialog-spinner"></div>
    </details-dialog>
  </details>
</template>

    <div class="Popover js-hovercard-content position-absolute" style="display: none; outline: none;" tabindex="0">
  <div class="Popover-message Popover-message--bottom-left Popover-message--large Box color-shadow-large" style="width:360px;">
  </div>
</div>

    <template id="snippet-clipboard-copy-button">
  <div class="zeroclipboard-container position-absolute right-0 top-0">
    <clipboard-copy aria-label="Copy" class="ClipboardButton btn js-clipboard-copy m-2 p-0 tooltipped-no-delay" data-copy-feedback="Copied!" data-tooltip-direction="w">
      <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-copy js-clipboard-copy-icon m-2">
    <path fill-rule="evenodd" d="M0 6.75C0 5.784.784 5 1.75 5h1.5a.75.75 0 010 1.5h-1.5a.25.25 0 00-.25.25v7.5c0 .138.112.25.25.25h7.5a.25.25 0 00.25-.25v-1.5a.75.75 0 011.5 0v1.5A1.75 1.75 0 019.25 16h-7.5A1.75 1.75 0 010 14.25v-7.5z"></path><path fill-rule="evenodd" d="M5 1.75C5 .784 5.784 0 6.75 0h7.5C15.216 0 16 .784 16 1.75v7.5A1.75 1.75 0 0114.25 11h-7.5A1.75 1.75 0 015 9.25v-7.5zm1.75-.25a.25.25 0 00-.25.25v7.5c0 .138.112.25.25.25h7.5a.25.25 0 00.25-.25v-7.5a.25.25 0 00-.25-.25h-7.5z"></path>
</svg>
      <svg aria-hidden="true" height="16" viewBox="0 0 16 16" version="1.1" width="16" data-view-component="true" class="octicon octicon-check js-clipboard-check-icon color-fg-success d-none m-2">
    <path fill-rule="evenodd" d="M13.78 4.22a.75.75 0 010 1.06l-7.25 7.25a.75.75 0 01-1.06 0L2.22 9.28a.75.75 0 011.06-1.06L6 10.94l6.72-6.72a.75.75 0 011.06 0z"></path>
</svg>
    </clipboard-copy>
  </div>
</template>


    <style>
      .user-mention[href$="/MYSTRANsolver"] {
        color: var(--color-user-mention-fg);
        background-color: var(--color-user-mention-bg);
        border-radius: 2px;
        margin-left: -2px;
        margin-right: -2px;
        padding: 0 2px;
      }
    </style>


  </body>
</html>

