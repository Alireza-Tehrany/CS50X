 int characters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int len = strlen(text);
    int arrLen = sizeof characters / sizeof characters[0];

    for (int i = 0; i <= arrLen; i++)
    {
        for (int j = 0; j< len ; j++)
        {
            if (text[j] == characters[i])
            {
                letters = letters + 1;
                break;
            }
        }
    }



    int letters = 0;
    for (int i = 0; text[i] != '\0'; i++)
        {
            if (isalpha(text[i]))
            {
                letters = letters + 1;
                break;
            }
        }