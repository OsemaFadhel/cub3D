#include "include/cub3d.h"

void	*ft_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
	{
		error(0, "A malloc error occured, exiting the program\n", 0);
		exit(EXIT_FAILURE);
	}
	return (ret);
}

char	*ft_strdup_mod2(char *s, int start, int end)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = end - start;
	dup = ft_malloc(sizeof(*dup) * len + 1);
	i = 0;
	while (s[start] == ' ')
		start++;
	while (s[start] && start < end)
	{
		dup[i] = s[start];
		i++;
		start++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*parse_texture(char *path)
{
	int		fd;
	char	**new_path;
	char	*first_path;
	int		i;

	i = 0;
	new_path = ft_split(path, ' ');
	if (new_path[1] != 0)
		return (0);
	fd = open(new_path[0], O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	first_path = ft_strdup_mod2(new_path[0], 0, ft_strlen(new_path[0]));
	while(new_path[i])
	{
		free(new_path[i]);
		++i;
	}
	free(new_path);
	return (first_path);
}

int	get_texture(char *line, int type, t_game *cub, int start)
{
	char *tmp;

	tmp = ft_strdup_mod2(line, start + 3, ft_strlen(line) - 1);
	if (type == 1)
	{
		cub->textures.no = parse_texture(tmp);
		printf("north texture: %s\n", cub->textures.no);
	}
	else if (type == 2)
	{
		cub->textures.so = parse_texture(tmp);
		printf("south texture: %s\n", cub->textures.so);
	}
	else if (type == 3)
	{
		cub->textures.we = parse_texture(tmp);
		printf("west texture: %s\n", cub->textures.we);
	}
	else if (type == 4)
	{
		cub->textures.ea = parse_texture(tmp);
		printf("east texture: %s\n", cub->textures.ea);
	}
	free(tmp);
	return (0);
}

void	ft_free(char **str, char *line)
{
	int	i;

	i = 0;
	if (line)
		free(line);
	else if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

int	ft_atoi_mod(const char *str, int type)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - 48;
	}
	if (str[i] == '\n')
		i++;
	if ((sign * res > 2147483647 || sign * res < -2147483647) || str[i])
	{
		while (type == 2 && (str[i] == ' ' || str[i] == '\n'))
			i++;
		if (!str[i])
			return (sign * res);
		else
			return (-2);
	}
	return (sign * res);
}

void	set_color(t_game *cub, char *line, int type)
{
	char	**rgb;
	int		i;
	int		current;

	rgb = ft_split(line, ',');
	if (rgb[0] && rgb[1] && rgb[2] && !rgb[3])
	{
		i = 0;
		current = 0;
		while (rgb[i])
		{
			current = ft_atoi_mod(rgb[i], i);
			if (current < 0 || current > 255)
				error(cub, "Invalid RGB value\n", 0);
			if (type == 1)
				cub->map.ceiling = (cub->map.ceiling << 8) + current;
			else
				cub->map.floor = (cub->map.floor << 8) + current;
			i++;
		}
	}
	else
		error(cub, "Invalid RGB value\n", 0);
	ft_free(rgb, 0);
}

int	get_color_2(char *line, int type, t_game *cub, int start)
{
	char *tmp;

	if (type == 1)
	{
		tmp = ft_strdup_mod2(line, start + 2, ft_strlen(line));
		set_color(cub, tmp, 2);
		free(tmp);
	}
	else if (type == 2)
	{
		tmp = ft_strdup_mod2(line, start + 2, ft_strlen(line));
		set_color(cub, tmp, 1);
		free(tmp);
	}
	return (0);
}

static void	continue_catch(char *line, t_game *cub, int res, int i)
{
	printf("line[i]: %c\n", line[i]);
	if (line[i] == 'N' && line[i + 1] == 'O')
		res = get_texture(line, 1, cub, i);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		res = get_texture(line, 2, cub, i);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		res = get_texture(line, 3, cub, i);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		res = get_texture(line, 4, cub, i);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		res = get_color_2(line, 1, cub, i);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		res = get_color_2(line, 2, cub, i);
	else if ((line[i] != '\n') || res == -1)
	{
		error(cub, "Something went wrong with map file\n", 0);
	}
}

int	get_map_size_2(char *line, t_game *cub)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E')
		{
			cub->map.player_x = i;
			cub->map.player_y = cub->map.y;
			cub->map.player_found = 1;
			cub->map.player_orientation = line[i];
		}
		i++;
	}
	if (line[i - 2] == '1' || line[i - 1])
	{
		cub->map.y += 1;
		if (i > cub->map.x)
			cub->map.x = i;
		return (0);
	}
	return (-1);
}

void	catch_textures(char *line, t_game *cub, int line_count)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	if (line[0] == ' ' || line[0] == '1')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
		{
			if (cub->map.start_line == 0)
				cub->map.start_line = line_count;
			res = get_map_size_2(line, cub);
		}
		else
			continue_catch(line, cub, res, i);
	}
	else
		continue_catch(line, cub, res, i);
}


char	*read_current_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_strdup_modif(char *s, int start, int end)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = end - start;
	dup = ft_malloc(sizeof(*dup) * len + 1);
	i = 0;
	while (s[start] && start < end)
	{
		if (s[start] == '\n')
			dup[i] = ' ';
		else
			dup[i] = s[start];
		i++;
		start++;
	}
	while (start < end)
	{
		dup[i] = ' ';
		i++;
		start++;
	}
	dup[i] = '\0';
	return (dup);
}

static int	insert_map(t_game *cub, int fd, int i, char *line)
{
	while (i < cub->map.y)
	{
		cub->map.map[cub->map.y - 1] = ft_malloc(sizeof(char) * cub->map.x);
		i++;
	}
	i = 0;
	while (i < cub->map.start_line - 1)
	{
		line = read_current_line(fd);
		if (!line)
			return (-1);
		free(line);
		i++;
	}
	i = 0;
	while (i < cub->map.y)
	{
		line = read_current_line(fd);
		if (!line)
			return (-1);
		cub->map.map[i] = ft_strdup_modif(line, 0, (cub->map.x - 1));
		free(line);
		i++;
	}
	return (0);
}

void	ft_swap_double(double *x, double *y)
{
	double	tmp;

	tmp = *x;
	*x = *y + 0.5;
	*y = tmp + 0.5;
}

int	store_map(char *file, t_game *cub)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	cub->map.map = ft_malloc(sizeof(char *) * cub->map.y);
	if (insert_map(cub, fd, i, line) == -1)
		return (-1);
	close(fd);
	cub->map.map[(int)cub->map.player_y][(int)cub->map.player_x] = '0';
	ft_swap_double(&cub->map.player_x, &cub->map.player_y);
	return (0);
}

void	call_suite(t_game *cub, char *file)
{
	//check_texture(cub);
	store_map(file, cub);
	//if (!check_map(cub) || !cub->map.player_found)
		//error(cub, "Something went wrong with the map\n", 0);
}

int	check_file2(char *file, t_game *cub)
{
	int		fd;
	int		line_count;
	char	*line;

	line = "";
	line_count = 0;
	fd = open(file, O_RDONLY);
	printf("fd: %d\n", fd);
	if (fd == -1)
		error(cub, "Can't open file\n", 1);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		line_count++;
		catch_textures(line, cub, line_count);
		free(line);
	}
	close(fd);
	call_suite(cub, file);
	return (0);
}
