% FOO_SCRIPT_MORE   Generate dynamic library foo from foo.
% 
% Script generated from project 'foo.prj' on 05-Aug-2024.
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
ARGS{1} = cell(1,1);
ARGS{1}{1} = coder.typeof(0,[1 60000],[0 1]);

%% Invoke MATLAB Coder.
codegen -config cfg foo -args ARGS{1}

