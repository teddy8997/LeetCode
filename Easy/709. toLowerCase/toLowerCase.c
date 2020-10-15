char * toLowerCase(char * str){
    /*
    檢查大寫str[i]>='A'&&str[i]<='Z'
    大寫換小寫+32
    小寫換大寫-32
    */
    int i;
    char *text;
    text = malloc(strlen(str) * sizeof(char));
    for(i = 0; i < strlen(str); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            text[i] = str[i] + 32;
        }else{
            text[i] = str[i];
        }
    }
    return text;
}