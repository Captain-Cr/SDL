#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


/*
	Describe: 绘制文字
	
*/

#define WIDTH 600
#define HIGHT 500
#define FRAMERATE 30	// 帧频率，30fps
#define FONT_SIZE 32	// 字体大小

int x = 0;
SDL_Surface *img;       // 图片指针
TTF_Font *font;		// 字体指针


void draw(SDL_Surface *screen, SDL_Window *win)
{
    SDL_Rect src = {0, 0, img->w, img->h};                // 获取图像绘制区域
    SDL_Rect dst = {0, 0, WIDTH, HIGHT};                    // 窗口区域
    SDL_BlitSurface(img, &src, screen, &dst);                 // 将图片绘制到窗口surface上

    // 字体设置
    SDL_Color color = {255, 255, 0, 255};	// RGBA
    struct SDL_Surface *text = TTF_RenderUTF8_Blended(font, "hello world",color);	// 字体surface
    SDL_Rect src2 = {0, 0, text->w, text->h};
    SDL_BlitSurface(text, &src2, screen, &dst);	//用此函数来快速地拷贝一个表面内容到目标表面

    // 把不用的surface清除掉
    //SDL_FreeSurface(text);
    //SDL_FreeSurface(img);
    SDL_UpdateWindowSurface(win);                           // 更新窗口
}



void sdl_event_loop(SDL_Surface *screen, SDL_Window *win)
{
	// 循环检测事件，并打印输出事件的类型
    while(1)
    {
	    uint32_t begin = SDL_GetTicks();	// 获取开始时间

            SDL_Event  event;
	        draw(screen, win);		// 绘制
            while(SDL_PollEvent(&event))
            {
                printf("event type, %d\n", event.type);
                if(event.type == SDL_QUIT)
                {
                    return;
                }
            }
	    
	    // 设定固定帧率
	    uint32_t current = SDL_GetTicks();	   // 获取当前时间
	    uint32_t cost = current - begin;	   // 获取程序运行的时间
	    uint32_t TimeByOneFrame = 1000 / FRAMERATE;	// 一帧所需要的时间,ms
	    long delay = TimeByOneFrame - cost;
	    
	    if(delay > 0)
	    {
	    	SDL_Delay(delay);	// 20ms，50fps
	    }
    }
}

int main()
{
    if(TTF_Init())
    {
	SDL_Log("can not init ttf, %s", TTF_GetError());
	return 1;
    }
    // 初始化窗口，成功返回0
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Can not init video, %s", SDL_GetError());
        return 1;
    }

    // 创建一个窗口指针
    SDL_Window *win = SDL_CreateWindow(
                                                        "Hello world",
                                                        SDL_WINDOWPOS_CENTERED,
                                                        SDL_WINDOWPOS_CENTERED,   
							WIDTH,  HIGHT,
                                                        SDL_WINDOW_SHOWN);

    if(win == NULL)
    {
        SDL_Log("Can not create window, %s",SDL_GetError());
        return 1;
    }

    

    /*
    SDL_Surface *screen = SDL_GetWindowSurface(win);	// screen是指向创建窗口的指针
    SDL_Rect r = {0, 0, WIDTH/2, HIGHT/2};		// 矩形结构体
    SDL_FillRect(screen, &r, 0xff00ff00);			// 4个字节，32位，ARGB
    

    // 修改像素,  (知道了高、宽以及每一个像素是4个字节,  screen->pixels是一个无符号指针)
    for(int i = HIGHT / 2; i < HIGHT; i++)
    {
	for(int j = WIDTH / 2; j < WIDTH; j++)
	{
	    ((uint32_t *)(screen->pixels))[i*WIDTH + j] = 0xffff0000;
	}
    }
    
    SDL_UpdateWindowSurface(win);			// 更新窗口，渲染
    */

    SDL_Surface * screen = SDL_GetWindowSurface(win);       // 获取窗口的指针
    img =  IMG_Load("/home/rose/mount/code/sdl_learning7_LoadImg/cat.jpg");   // 加载图片
	
    // 打开字体文件
    font = TTF_OpenFont("/home/rose/mount/code/sdl_learning8_DrawText/padmaa.ttf",FONT_SIZE);		 
    if(font == NULL)
    {
	SDL_Log("Can not open font file");
	return 1;
    }

    sdl_event_loop(screen, win);             // 打印事件类型



    SDL_Delay(300);
    SDL_FreeSurface(img);               // 销毁掉img的surface
    TTF_CloseFont(font);		// 关闭字体文件
    SDL_DestroyWindow(win);

    return 0;
}
