int	ft_treat_s_with_width(const char *format, t_data *data)
{
	int len;
	int i;
	char *str;
	
	i = -1;
	str = va_arg(ap, char *)
	len = data->width - ft_strlen(str);//mettre une fonction pour vérifier si '-' ou '0'
	if (len < 0)
		return ;
	while (++i < len)
		buf[i] = ' ';//allouer de la mémoire ou trouver un moyen de le stocker dans le buf 
	return ;
}
	

	
