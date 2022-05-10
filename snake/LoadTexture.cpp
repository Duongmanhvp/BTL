#include "LoadTexture.h"

SDL_Texture *loadTexture(std::string path, SDL_Renderer *&gRenderer)
{
     // The final texture
     SDL_Texture *newTexture = NULL;

     // Load image at specified path
     SDL_Surface *loadedSurface = IMG_Load(path.c_str() );
     if (loadedSurface == NULL)
     {
          printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
     }
     else
     {
          // Create texture from surface pixels
          newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
          if (newTexture == NULL)
          {
               printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
          }

          // Get rid of old loaded surface
          SDL_FreeSurface(loadedSurface);
     }

     return newTexture;
}
void renderTextTexture(SDL_Renderer *&gRenderer, const std::string &fontName,
                       const std::string &content, const int &fontSize,
                       const SDL_Color &fcolor, const int &x, const int &y)
{
     TTF_Font *font = TTF_OpenFont(fontName.c_str(), fontSize);

     SDL_Surface *surface = TTF_RenderText_Solid(font, content.c_str(), fcolor);
     SDL_Texture *texture = SDL_CreateTextureFromSurface(gRenderer, surface);
     SDL_FreeSurface(surface);
     surface = NULL;

     int w, h;
     SDL_QueryTexture(texture, NULL, NULL, &w, &h);
     SDL_Rect desRect = {x, y, w, h};
     SDL_RenderCopy(gRenderer, texture, NULL, &desRect);

     TTF_CloseFont(font);
     font = NULL;
     SDL_DestroyTexture(texture);
     texture = NULL;

/*   bool isRunning = true;
     SDL_Event mainEvent;
     SDL_Window* window = NULL;


     TTF_Font *font = TTF_OpenFont("VeraMoBd.ttf", 30);
     SDL_Color fg = { 243, 156, 18 };

	 std::string text = "Your Scores: ";
     SDL_Surface *surface = TTF_RenderText_Solid(font, content.c_str(), fcolor);
     SDL_Texture *texture = SDL_CreateTextureFromSurface(gRenderer, surface);
     SDL_FreeSurface(surface);
     surface = NULL;

     SDL_Rect srcRest;
	SDL_Rect desRect;
	TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h);

	srcRest.x = 0;
	srcRest.y =  0;

	desRect.x = 400;
	desRect.y = 400;

	desRect.w = srcRest.w;
	desRect.h = srcRest.h;
	//set background color
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
	//main loop
	while (isRunning)
	{
		//main event
		while (SDL_PollEvent(&mainEvent))
		{
			switch (mainEvent.type)
			{
				//User - requested quit
				case SDL_QUIT:
				{
					isRunning = false;
					break;
				}
				default:
				{
					break;
				}
			}
		}
		// clear the window to black
		SDL_RenderClear(gRenderer);
		//Copy a portion of the texture to the current rendering target.
		SDL_RenderCopy(gRenderer, texture, &srcRest, &desRect);
		//draw to screen
		SDL_RenderPresent(gRenderer);
	}
	//Destroy a window.
	SDL_DestroyWindow(window);
	//Destroy a renderer
	SDL_DestroyRenderer(gRenderer);
	//Shutdown and cleanup the truetype font API.
	TTF_Quit();


*/


}
