function B = foo(input)

[Y,F_temp]=periodogram(input(1:48:end),[],0:99,1000);
Y=Y./max(Y);
B=[F_temp,Y];

end