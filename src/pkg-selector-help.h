//  Textdomain "yast2-gtk"

static const char *pkg_help =
"<h1>Purpose</h1>"
"<p>This tool lets you manage software, as in 'install, remove, update applications'.</p>"
"<p>openSUSE's software management is also called 'package management'. A package is "
"generally an application bundle, but multiple packages that extend the application "
"may be offered in order to avoid clutter (e.g. games tend to de-couple the music "
"data in another package, since its not essential and requires significant disk space). "
"The base package will get the application's name, while extra packages are suffix-ed. "
"Common extras are:</p>"
"<ul>"
"<li>-plugin-: extends the application with some extra functionality.</li>"
"<li>-devel: needed for software development.</li>"
"<li>-debuginfo: needed for software beta-testing.</li>"
"<li>-fr, -dr, -pl (language siglas): translation files (your language package will "
"be marked for installation automatically).</li>"
"</ul>"
"<p>You will find both packages installed on your system, and packages that are made "
"available through the setup-ed repositories. You cans either install or upgrade "
"an available package, or remove an installed one.</p>"
"<blockquote>A repository is a packages media; it can either be local (like your Suse CDs), "
"or a remote internet server. You can find utilities to setup repositories "
"on the YaST control center.</blockquote>"
""
"<h1>Usage</h1>"
"<h2>Available, Upgrades, Installed buttons</h2>"
"<p>These buttons produce listings of the different sources of packages. 'Available' "
"are the ones from the setup-ed repositories less those you have installed. "
"'Installed' lists the packages installed in your system. 'Upgrades' is a "
"mix listing of the installed packages that have more recent versions available. "
"'All' will combine all sources.</p>"
""
"<h2>Filters</h2>"
"<p>Enter free text into the search-field to match their names and descriptions. "
"(a search for 'office' will bring up the 'OpenOffice' packages as well as "
"AbiWord which carries the word 'office' in its description). You can also "
"choose to view software from a specific repository.</p>"
""
"<h2>Categories &amp; Collections</h2>"
"<p>Software for openSUSE is indexed so that you can find software for a specific "
"task when you don't know the name of the software you are looking for. Browse "
"indices of software by using the tree-view in the left column; you can view the "
"available software by their Package names, or grouped in 'Categories' or 'Patterns' "
"by the selecting a view-mode from the drop-down-menu below. Categories' are simple, "
"hierarchical classifications of software packages, like 'Multimedia/Video', while "
"'Patterns' are task-oriented collections of multiple packages that install like one "
"(the installation of the 'server'-pattern for example will install various software "
"needed for running a server). By using 'Install All' you make sure that future "
"collection changes, when you upgrade openSUSE, will be honored.</p>"
""
"<h2>Software details in the box below</h2>"
"<p>In the package detail view you can perform actions affecting this software; "
"like install, uninstall, version-upgrade or -downgrade. All changes that you "
"make will be saved, but not yet performed.</p>"
"<p>You can review changes in the right-side pane of the software-manager. You can "
"revoke changes individually at any time by clicking the 'undo'-button next to "
"a saved change.</p>"
"<p>The lock button can be used to lock the selected package state; it won't allow "
"some automatic operation to install, upgrade or remove the package. This is only "
"useful in very unusual cases: for instance, you may not want to install some "
"drivers because they interfer with your system, yet you want to install some "
"collection that includes them.</p>"
"<p>The changes will be performed once you decide to click the 'perform changes' "
"button in the lower-right corner. If you want to leave the software-manager "
"without performing any changes, simply press the button labeled 'Abort'.</p>"
""
"<blockquote><i>Developed by Ricardo Cruz &lt;rpmcruz@alunos.dcc.fc.up.pt&gt;<br>" 
"Thanks to Christian Jäger for co-designing this tool.</i></blockquote>";

static const char *patch_help =
"<h1>Purpose</h1>"
"<p>This tool gives you control on overviewing and picking patches. You may also "
"reverse patches that have been applied to the system.</p>"
""
"<h1>Usage</h1>"
"<h2>Categories</h2>"
"<p>Patches are grouped as follows:</p>"
"<ul>"
"<li>Security: patches a software flaw that could be exploited to gain "
"restricted privilege.</li>"
"<li>Recommended: fixes non-security related flaws (e.g. data corruption, "
"performance slowdown)</li>"
"<li>Optional: ones that only apply to few users.</li>"
"</ul>"
"<p>Only patches that apply to your system will be visible. openSUSE developers "
"are very restrained in pushing patches; you can be sure that all patches are "
"of signficant severity.</p>"
"<p>If you are looking for applications enhancements, you should check for Upgrades "
"on the Software Manager.</p>";

