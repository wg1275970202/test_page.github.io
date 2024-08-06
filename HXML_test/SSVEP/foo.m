function Out = foo(input)
%%
% input=[1,rand(1,30e3),12,0.1];
% Precompute indices
Siz = [1, 30e3, 1, 1];
n_ = cumsum(Siz);

% Extract parameters from input
duration = input(1);
data = input(2:(duration*1000+1));
F1 = input(n_(3));
df = input(n_(4));

% Display parameters% Display parameters using sprintf
% fprintf('F1 = %.2f\n', F1)
% fprintf('df = %.2f\n', df)
disp("duration")
disp("data")
disp("F1="+F1)
disp("df="+df)

% Define frequency range
f_range = single(0:0.1:50);

% Compute periodogram
[Y, F_temp] = periodogram(data, [], f_range, 1000);
Y = Y / max(Y);
B1 = [F_temp, Y]; % Ensure F_temp is a column vector for concatenation

% Display B1
disp("B1 done")

% 
% Define XX
XX=false(100,1);
XX([13	23	33	43	53	59	60	63	67	68	73	76	84	85])=true;

disp("B2 done 1")

% Compute additional metrics
Indicators=single(zeros(1,11));
Indicators = fun(data, XX(:));

disp("B2 done 2")

% Combine results
B2 = single(Indicators);

disp("B2 done 3")

% Output the combined result
Out = single([B1 B2]); % Ensure concatenation aligns properly
%%
end
