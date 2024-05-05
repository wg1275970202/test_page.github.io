


repo = gitrepo
%%

pull(repo)

%%
commitMessage="NEW";
commitDetails = commit(repo,Message=commitMessage)

%%
push(repo);

%%


