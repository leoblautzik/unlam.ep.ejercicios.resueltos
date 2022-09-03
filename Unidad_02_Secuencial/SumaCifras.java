public class SumaCifras {
   /* Version iterativa con dos while anidados
    */ 
   static long sumacifras(long numero) {
        long i, sum; 
        while(numero > 9){
            i = 1;
            sum = 0;
            while(numero >= i ) {
                sum += (numero / i) % 10;
                i*=10;
            }
            numero = sum;
        }
        return numero;
    }
    /* Version matematica: La suma de las cifras es num % 9 con la salvedad 
     * de que si es multiplo de 9 la suma de las cifras es 9
     */
    static long sumacifrasX9(long n) {
        long suma = n % 9;
        if(suma == 0) suma = 9;
        return suma;
    }

    public static void main(String [] args) {
        long numero = 123456789;
        System.out.println(sumacifras(numero));
        System.out.println(sumacifrasX9(numero));
    }
}
