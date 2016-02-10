#include <mex.h>
#include <matrix.h>
#include "spline_gsl.cpp"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
	double *yy, *YY;
	double *xx, *XX;
	double *y, *Y;
	double *x, *X;
	
	int m1, n1;
	int m2, n2;
	int m3, n3;

	/* parse input arguments */
	X  = mxGetPr(prhs[0]);
	m1 = mxGetM(prhs[0]);
	n1 = mxGetN(prhs[0]);
	int l1 = m1 * n1;

	Y  = mxGetPr(prhs[1]);
	m2 = mxGetM(prhs[1]);
	n2 = mxGetN(prhs[1]);
	int l2 = m2 * n2;

	XX  = mxGetPr(prhs[2]);
	m3 = mxGetM(prhs[2]);
	n3 = mxGetN(prhs[2]);
	int l3 = m3 * n3;

	/* initialize arrays */
	x  = new double[l1];
	y  = new double[l1];
	yy = new double[l3];
	// YY = new double[l3];
	// x = new int[sz1];


	for (int i = 0; i < l1; i++) {
		x[i] = X[i];
		y[i] = Y[i];
	}

	/* create output arguments */
	plhs[0] = mxCreateDoubleMatrix(1, l3, mxREAL);
	YY = mxGetPr(plhs[0]);

	/* call core function */
	spline(yy, x, y, XX, l1, l3);

	for(int i = 0; i < l3; i++) {
		// YY[i] = 0;
		YY[i] = yy[i];
	}


}