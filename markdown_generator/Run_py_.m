
%%

! start excel talks.tsv
%%
rmdir("..\_talks","s")
mkdir("..\_talks")
pyrunfile("talks.py")

%% proceeding
open("proceedings.bib")

%% journal
open("pubs.bib")

%%
rmdir("..\_publications","s")
mkdir("..\_publications")
pyrunfile("pubsFromBib.py")
