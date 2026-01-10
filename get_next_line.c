#include "get_next_line.h"

static char	*read_and_stash(int fd, char *stash)
{
	int		bytes;
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;

	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(stash);
			return (NULL);
		}
		buffer[bytes] = '\0';
		tmp = ft_strjoin(stash, buffer);
		if (!tmp)
			return (NULL);
		stash = tmp;
	}
	return (stash);
}

static char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	return (line);
}

static char	*clean_stash(char *stash)
{
	char	*tmp;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	tmp = ft_substr(stash, i + 1, ft_strlen(stash) - i - 1);
	free(stash);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
