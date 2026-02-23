function dW_dai = dW_dai_fcn(i,x,a)
dW_dai =(i==1)*dW_da1(x,a)+(i==2)*dW_da2(x,a);