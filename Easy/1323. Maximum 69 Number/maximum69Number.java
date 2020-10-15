    public int maximum69Number (int num) {
        String s = Integer.toString(num);
        String result = "";
        boolean flag = false;
        for(int i = 0; i < s.length(); i++){
            if(flag != false && s.charAt(i) == '6'){
                result += "9";
                flag = true;
            }else{
                result += s.charAt(i);
            }
        }
        return Integer.parseInt(result);
    }
}