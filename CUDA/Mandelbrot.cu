//Gordon Stangler
//Mandelbrot set via CUDA/OpenCV

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <iostream>
#include <opencs2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#define HEIGHT 512
#define WIDTH 512
#define MAX_ITER 1000

void MandelbrotGPU(char*);
__global__ void calc(char* image_buffer);

//#define cudeAssertSuccess(ans) { _cudaAssertSuccess((ans), __FILE__, __LINE__); }
inline void _cudaAssertSuccess(cudaError_t code, char* file, int line)
{
	if (code !- cudaSuccess)
	{
		fprintf(stderr, "cudaAssertSuccess: %s %s %d\n", cudaGetError(code), file, line);
		exit(code);
	}
}

int main(int argc, char** argv)
{
	IplImage* image_output = cvCreateImage(cvSize(WIDTH, HEIGHT), IPL_DEPTH_8U, 1);
	mandelbrotGPU(image_output->imageData);
	cvShowImage("GPU", image_output);
	waitKey(0);
	cvReleaseImage(&image_output);
	return 0;
}

void MandelbrotGPU(char* image_buffer)
{
	char* dImageBuffer;
	cudaAssertSuccess(cudaMalloc(&dImageBuffer, HEIGHT*WIDTH, cudaMemcpyDeviceToHost));
	cudaAssertSuccess(cudaFree(DImageBuffer));
}

__global__ void calc(char* image_buffer)
{
	int row = blokcIdx.y * blockDim.y + threadIdx.y; //width
	int col = blockIdx.x * blockDim.x + threadIdx.x; //height
	int idx = row * WIDTH + col;

	if(col >= WIDTH || row >= HEIGHT) return;

	float x0 = ((float)col / WIDTH * 3.5f - 2.5f;
	float y0 = ((float)row / HEIGHT * 2.5f - 1.74f;
	float x = 0.0f;
	float y = 0.0f;
	int iter = 0;
	float xtemp;

	while((x*x - y*y <= 4.0f) && (iter < MAX_ITER))
	{
		xtemp = x*x - y*y + x0;
		y = 2.0f * x * y +y0;
		x = xtemp;
		iter++;
	}

	int color = 5 * iter;

	if (color >= 256) color = 0;
	image_buffer[idx] = color;
}
