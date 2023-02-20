/*
	Description:使用SDL进行图形绘制和文字绘制
	
	Copyright:2023-2-19 
*/

#include <iostream>
extern "C"
{	
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
}

#define WIDTH 600		// 宽
#define HIGHT 500		// 高
#define FRAMERATE 30	// 帧率

typedef void (*CallFunction)(SDL_Window *win, SDL_Renderer *renderer);		// 定义回调函数原型，函数指针名称为CallFunction,该函数传入两个参数，返回类型为void
using namespace std;




void callbackfunction(SDL_Window *win, SDL_Renderer *renderer)
{
	// 回调函数， 可根据不同任务编写不同代码
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);
	
	//显示图像
	SDL_RenderPresent(renderer);
	
}


void RendererGraphics(SDL_Window *win, SDL_Renderer *renderer)
{
	// 图形渲染
	// 图像在SDL中被封装成一个叫做纹理的结构体SDL_Texture
	// SDL_Texture 代表了所有像素相关的内容数据，要想在程序中显示图像，首先要将图像转化为纹理结构才可以
	// SDL_CreateTexture和SDL_DestroyTexture来创建和销毁纹理
	// 一般情况都是从硬盘直接加载相关图片转化为纹理结构体。在使用SDL显示图像前，要先将图片加载到内存，保存为SDL_Surface结构体，然后转换为支持硬件加速的结构体SDL_Texture，最后通过拷贝操作，将纹理数据暂存到后台缓冲区。

	// 清空Renderer
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);	

	SDL_Surface *image = IMG_Load("/home/rose/mount/code/sdl_external_DrawGraphical/sdl_2/1.jpg");
	SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, image);       // 纹理结构体
	SDL_RenderCopy(renderer, tex, NULL, NULL);
	
	//显示图像
	SDL_RenderPresent(renderer);	

	SDL_FreeSurface(image);
	SDL_DestroyTexture(tex);
	
}


void sdl_event_loop(SDL_Window *win, SDL_Renderer *renderer,CallFunction callback)
{
	// 循环事件, 可以在里面负责渲染等工作
	// Args:
	// 		CallFunction callback是回调函数，负责渲染等工作
	
	while(1)								// 不断检测事件
	{
		
		uint32_t begin = SDL_GetTicks();	// 获取开始时间
		SDL_Event event;
		if(SDL_PollEvent(&event))		
		{
			if(event.type == SDL_QUIT)		// 退出循环
			{
				return;
			}
		}
		
		callback(win, renderer);		// 执行回调函数
		
		//设定固定帧率
		uint32_t current = SDL_GetTicks();	// 获取当前时间
		uint32_t cost = current - begin;	// 当前程序运行的总花费时间
		uint32_t TimeByOneFrame = 1000 / FRAMERATE;		// 一帧需要的时间，ms
		long delay = TimeByOneFrame - cost;				// 需要延时的时长，如果程序花费时间大于一帧的时间，那么就不延时;否则延时的时长为delay
		if(delay > 0)
		{
			SDL_Delay(delay);	
		}
	}
}




int main(int argc, char* argv[])
{
	// 初始化sdl
	if(SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("Can not init video, %s", SDL_GetError());
		return 1;
	}
	
	// 创建窗口指针
	SDL_Window *win = SDL_CreateWindow(
											"Renderer Graphics",
											SDL_WINDOWPOS_CENTERED,
											SDL_WINDOWPOS_CENTERED,
											WIDTH, HIGHT,
											SDL_WINDOW_SHOWN);
	if(win == NULL)
	{
		SDL_Log("Can not create window, %s",SDL_GetError());
		return 1;
	}
	
	
	// 创建着色器指针
	SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL)
	{
		SDL_Log("Can not create Renderer, %s",SDL_GetError());
	}
	
	// 循环事件， 负责渲染
	sdl_event_loop(win, renderer, RendererGraphics);
	
	
	
	
	// 销毁指针
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);

	
	return 0;
	
	
	
	
}
