
repo = gitrepo
%%
fetch(repo)
pull(repo)
%%
commitMessage="NEW";
commitDetails = commit(repo,Message=commitMessage)
%%
push(repo);
%%


