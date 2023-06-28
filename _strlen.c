/**
 * _strlen - count the length of a character
 * @s: the character to be counted
 * Return: the length integer
 */
int _strlen(const char *s)
{
	int len = 0;
	int k;

	for (k = 0; s[k] != '\0'; k++)
	{
		len++;
	}
	return (len);
}
