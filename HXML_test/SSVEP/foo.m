function B = foo(input,duration)

[Y,F_temp]=periodogram(input(1:duration*1000),[],0:0.25:50,1000);
Y=Y./max(Y);
B=single([F_temp,Y]);

end