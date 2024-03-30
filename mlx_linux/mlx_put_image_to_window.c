/*
** mlx_put_image_to_window.c for MiniLibX in raytraceur
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Mon Aug 14 15:55:49 2000 Charlie Root
** Last update Sun Oct  2 09:53:00 2005 Olivier Crouzet
*/



#include	"mlx_int.h"


int	mlx_put_image_to_window(t_xvar *xvar,t_win_list *win,t_img *img,
				int x,int y)
{
  GC	gc;

  gc = win->gc;
  if (img->gc)
    {
      gc = img->gc;
      XSetClipOrigin(xvar->display, gc, x, y);
    }
  if (img->type==MLX_TYPE_SHM)
    XShmPutImage(xvar->display,img->pix, win->gc, img->image,0,0,0,0,
		 img->width,img->height,False);
  if (img->type==MLX_TYPE_XIMAGE)
    XPutImage(xvar->display,img->pix, win->gc, img->image,0,0,0,0,
	      img->width,img->height);
  XCopyArea(xvar->display,img->pix,win->window, gc,
	    0,0,img->width,img->height,x,y);
  if (xvar->do_flush)
    XFlush(xvar->display);
}

/*void    mlx_put_image_to_window(mlx_ptr_t *mlx_ptr, mlx_win_list_t *win_ptr, mlx_img_list_t *img_ptr, int x, int y)
{
  mlx_img_ctx_t	*imgctx;

  if (!win_ptr->pixmgt)
    return ;

  [(id)(win_ptr->winid) selectGLContext];
  imgctx = add_img_to_ctx(img_ptr, win_ptr);

  // update texture
  glBindTexture(GL_TEXTURE_2D, imgctx->texture);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, img_ptr->width, img_ptr->height, 0,
	       GL_BGRA, GL_UNSIGNED_BYTE, img_ptr->buffer);

  [(id)(win_ptr->winid) mlx_gl_draw_img:img_ptr andCtx:imgctx andX:x andY:y];

  win_ptr->nb_flush ++;
}*/
