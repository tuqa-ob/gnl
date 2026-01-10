#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t			i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char		*result;
	size_t		len;
	size_t		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	result = malloc(sizeof(char) * (1 + len));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	char		m;
	int			i;

	if (!s)
		return (NULL);
	m = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == m)
			return ((char *)s + i);
		else
			i++;
	}
	if (m == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*result;
	size_t		i;
	size_t		strlen;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start >= strlen)
		return (ft_strdup(""));
	if (len > strlen - start)
		len = strlen - start;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*result;
	size_t		i;
	size_t		j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	result = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	j = 0;
	while (s1[i])
		result[j++] = s1[i++];
	i = 0;
	while (s2[i])
		result[j++] = s2[i++];
	result[j] = '\0';
	free(s1);
	return (result);
}
