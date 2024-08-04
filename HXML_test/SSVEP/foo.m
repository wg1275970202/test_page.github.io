function B = foo(input)
n=[30e3, 1 ];

n_=cumsum(n);
duration=input(n_(2));
data=input(1:duration*1000);

f_range=0:0.1:50;%length(f_range)
[Y,F_temp]=periodogram(data,[],f_range,1000);
Y=Y./max(Y);

B=single([F_temp,Y]);

end