! start excel talks.tsv
%%
pyrunfile("talks.py")


%% proceeding
open("proceedings.bib")


%% journal
open("pubs.bib")

%%

pyrunfile("pubsFromBib.py")
