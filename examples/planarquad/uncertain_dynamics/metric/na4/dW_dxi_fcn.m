function dW_dxi = dW_dxi_fcn(i,x,a)
dW_dxi =(i==3)*dW_dphi(x,a);