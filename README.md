# spline_mex
Matlab MEX of spline interpolation

## Usage

```
yi = mex_spline(x, y, xi);
```

### Example
```
x = 0:11;
y = randn(1, 11);
xx = 0:0.1:10;
yy = mex_spline(x, y, xx);
figure; plot(x,y, xx, yy);
```


## Compilation

### MAC
Requires **installation** of GNU Scientific Library (GSL).
```
mex -I/opt/local/include/ mex_spline.cpp -lgsl -lgslcblas -lm
```

Replace `/opt/local/include/` with your path of `gsl/`.


### Windows 
To be updated...
