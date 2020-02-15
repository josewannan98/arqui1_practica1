/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package arqi;

/**
 *
 * @author herre
 */
public class Arqi {

    static int Matriz1[][] = new int[8][15];

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        // TODO code application logic here
       
        putamadre a = new putamadre();
        //a.RecorridoG();
        a.Texto();
        
    }
    
    
  
    public static void Motrar(){
        for (int i =15; i>-1;i--){
            for (int j=0;j<8;j++){
                System.out.println(Matriz1[i][j]);
            }
        }
    
    }
}
