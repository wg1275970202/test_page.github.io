% FOO_SCRIPT_   Generate dynamic library foo from foo.
% 
% Script generated from project 'foo.prj' on 24-May-2024.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.EmbeddedCodeConfig'.
cfg = coder.config('dll','ecoder',true);
cfg.HardwareImplementation.ProdHWDeviceType = 'Google->V8 Engine';
cfg.HardwareImplementation.TargetHWDeviceType = 'Google->V8 Engine';
cfg.TargetLang = 'C++';
cfg.GenerateReport = true;
cfg.MaxIdLength = 1024;
cfg.PostCodeGenCommand = 'wasm.coder.postcodegen.addCLinkage(buildInfo); wasm.coder.postcodegen.registerExportedFunctions(buildInfo)';
cfg.ReportPotentialDifferences = false;
cfg.Toolchain = 'Emscripten v3.1.60 | gmake (64-bit Windows)';

%% Define argument types for entry-point 'foo'.
ARGS = cell(1,1);
% ARGS{1} = cell(2,1);
ARGS{1}{1} = coder.typeof(single(0),[1 60e3],[0 0]);
% ARGS{1}{2} = coder.typeof(single(0));

% variable size (true) or fixed size (false).
%% Invoke MATLAB Coder.
codegen -config cfg foo -args ARGS{1}

%%
movefile("codegen\dll\foo\foo.js",pwd)
movefile("codegen\dll\foo\foo.wasm",pwd)

%%
% % pause(1)
% server = wasm.utilities.DevelopmentServer("Directory",pwd,"Port",8000);
% server.start();
% 
% 
% url = 'http://localhost:8000/index.html';
% web(url, '-browser')

%%
% server.stop();



