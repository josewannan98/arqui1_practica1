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
public class putamadre {

    int Matriz1[][] = new int[8][15];
    boolean Inicio = false;

    public void Texto() {

        for (int Col = 15; Col > -1; Col--) {
            for (int Fil = 0; Fil < 8; Fil++) {
                // letra G
                if (Col > 0 && Col < 8) {
                    Matriz1[2][2 + Col] = 1;
                    Matriz1[2][3 + Col] = 1;
                    Matriz1[2][4 + Col] = 1;
                    Matriz1[2][5 + Col] = 1;
                    Matriz1[2][6 + Col] = 1;
                    Matriz1[3][1 + Col] = 1;
                    Matriz1[3][2 + Col] = 1;
                    Matriz1[3][3 + Col] = 1;
                    Matriz1[3][4 + Col] = 1;
                    Matriz1[3][5 + Col] = 1;
                    Matriz1[3][6 + Col] = 1;
                    Matriz1[3][7 + Col] = 1;
                    Matriz1[4][1 + Col] = 1;
                    Matriz1[4][7 + Col] = 1;
                    Matriz1[3][1 + Col] = 1;
                    Matriz1[5][1 + Col] = 1;
                    Matriz1[5][3 + Col] = 1;
                    Matriz1[5][7 + Col] = 1;
                    Matriz1[6][1 + Col] = 1;
                    Matriz1[6][2 + Col] = 1;
                    Matriz1[6][3 + Col] = 1;
                    Matriz1[6][6 + Col] = 1;
                    Matriz1[6][7 + Col] = 1;
                    Matriz1[7][2 + Col] = 1;
                    Matriz1[7][3 + Col] = 1;
                    Matriz1[7][6 + Col] = 1;
                    Mostrar();
                    Reiniciar();
                    System.out.println("\n");

                } else if (Col > 8) {
                    Matriz1[2][Col - 6] = 1;
                    Matriz1[2][Col - 7] = 1;
                    Matriz1[3][Col - 6] = 1;
                    Matriz1[3][Col - 7] = 1;
                    Matriz1[4][Col - 1] = 1;
                    Matriz1[4][Col - 2] = 1;
                    Matriz1[4][Col - 3] = 1;
                    Matriz1[4][Col - 7] = 1;
                    Matriz1[5][Col - 1] = 1;
                    Matriz1[5][Col - 2] = 1;
                    Matriz1[5][Col - 3] = 1;
                    Matriz1[5][Col - 4] = 1;
                    Matriz1[5][Col - 5] = 1;
                    Matriz1[5][Col - 7] = 1;
                    Matriz1[6][Col - 4] = 1;
                    Matriz1[6][Col - 5] = 1;
                    Matriz1[6][Col - 6] = 1;
                    Matriz1[6][Col - 7] = 1;
                    Matriz1[7][Col - 6] = 1;
                    Matriz1[7][Col - 7] = 1;
                    Mostrar();
                    Reiniciar();
                    System.out.println("\n");
                }

            }

        }

    }

    public void RecorridoG(int Col) {

        for (int a = Col; a < 8; a++) {
            Matriz1[2][2 + a] = 1;
            Matriz1[2][3 + a] = 1;
            Matriz1[2][4 + a] = 1;
            Matriz1[2][5 + a] = 1;
            Matriz1[2][6 + a] = 1;
            Matriz1[3][1 + a] = 1;
            Matriz1[3][2 + a] = 1;
            Matriz1[3][3 + a] = 1;
            Matriz1[3][4 + a] = 1;
            Matriz1[3][5 + a] = 1;
            Matriz1[3][6 + a] = 1;
            Matriz1[3][7 + a] = 1;
            Matriz1[4][1 + a] = 1;
            Matriz1[4][7 + a] = 1;
            Matriz1[3][1 + a] = 1;
            Matriz1[5][1 + a] = 1;
            Matriz1[5][3 + a] = 1;
            Matriz1[5][7 + a] = 1;
            Matriz1[6][1 + a] = 1;
            Matriz1[6][2 + a] = 1;
            Matriz1[6][3 + a] = 1;
            Matriz1[6][6 + a] = 1;
            Matriz1[6][7 + a] = 1;
            Matriz1[7][2 + a] = 1;
            Matriz1[7][3 + a] = 1;
            Matriz1[7][6 + a] = 1;
            Mostrar();
            Reiniciar();
            System.out.println("\n");
        }

    }

    public void RecorridoSiete() {
        for (int a = 0; a < 8; a++) {
            Matriz1[2][6 + a] = 1;
            Matriz1[2][7 + a] = 1;
            Matriz1[3][6 + a] = 1;
            Matriz1[3][7 + a] = 1;
            Matriz1[4][1 + a] = 1;
            Matriz1[4][2 + a] = 1;
            Matriz1[4][3 + a] = 1;
            Matriz1[4][7 + a] = 1;
            Matriz1[5][1 + a] = 1;
            Matriz1[5][2 + a] = 1;
            Matriz1[5][3 + a] = 1;
            Matriz1[5][4 + a] = 1;
            Matriz1[5][5 + a] = 1;
            Matriz1[5][7 + a] = 1;
            Matriz1[6][4 + a] = 1;
            Matriz1[6][5 + a] = 1;
            Matriz1[6][6 + a] = 1;
            Matriz1[6][7 + a] = 1;
            Matriz1[7][6 + a] = 1;
            Matriz1[7][7 + a] = 1;
            Mostrar();
            Reiniciar();
            System.out.println("\n");
        }
    }

    public void RecorridoGuion() {
        for (int a = 0; a < 8; a++) {
            Matriz1[5][3 + a] = 1;
            Matriz1[5][4 + a] = 1;
            Matriz1[5][5 + a] = 1;
            Matriz1[5][6 + a] = 1;
            Mostrar();
            Reiniciar();
            System.out.println("\n");
        }
    }

    public void RecorridoS() {
        for (int a = 0; a < 8; a++) {
            Matriz1[2][2 + a] = 1;
            Matriz1[2][5 + a] = 1;
            Matriz1[2][6 + a] = 1;
            Matriz1[3][1 + a] = 1;
            Matriz1[3][2 + a] = 1;
            Matriz1[3][4 + a] = 1;
            Matriz1[3][5 + a] = 1;
            Matriz1[3][6 + a] = 1;
            Matriz1[3][7 + a] = 1;
            Matriz1[4][1 + a] = 1;
            Matriz1[4][4 + a] = 1;
            Matriz1[4][7 + a] = 1;
            Matriz1[5][1 + a] = 1;
            Matriz1[5][4 + a] = 1;
            Matriz1[5][7 + a] = 1;
            Matriz1[6][1 + a] = 1;
            Matriz1[6][2 + a] = 1;
            Matriz1[6][3 + a] = 1;
            Matriz1[6][4 + a] = 1;
            Matriz1[6][6 + a] = 1;
            Matriz1[6][7 + a] = 1;
            Matriz1[7][2 + a] = 1;
            Matriz1[7][3 + a] = 1;
            Matriz1[7][6 + a] = 1;

            Mostrar();
            Reiniciar();
            System.out.println("\n");
        }

    }

    public void RecorridoE() {

        for (int a = 0; a < 8; a++) {
            Matriz1[2][1 + a] = 1;
            Matriz1[2][2 + a] = 1;
            Matriz1[2][3 + a] = 1;
            Matriz1[2][4 + a] = 1;
            Matriz1[2][5 + a] = 1;
            Matriz1[2][6 + a] = 1;
            Matriz1[2][7 + a] = 1;
            Matriz1[3][1 + a] = 1;
            Matriz1[3][2 + a] = 1;
            Matriz1[3][3 + a] = 1;
            Matriz1[3][4 + a] = 1;
            Matriz1[3][5 + a] = 1;
            Matriz1[3][6 + a] = 1;
            Matriz1[3][7 + a] = 1;
            Matriz1[4][1 + a] = 1;
            Matriz1[4][4 + a] = 1;
            Matriz1[4][7 + a] = 1;
            Matriz1[5][1 + a] = 1;
            Matriz1[5][4 + a] = 1;
            Matriz1[5][7 + a] = 1;
            Matriz1[6][1 + a] = 1;
            Matriz1[6][4 + a] = 1;
            Matriz1[6][7 + a] = 1;
            Matriz1[7][1 + a] = 1;
            Matriz1[7][7 + a] = 1;
            Mostrar();
            Reiniciar();
            System.out.println("\n");
        }

    }

    public void RecorridoC() {
        for (int a = 0; a < 8; a++) {
            Matriz1[2][2 + a] = 1;
            Matriz1[2][3 + a] = 1;
            Matriz1[2][4 + a] = 1;
            Matriz1[2][5 + a] = 1;
            Matriz1[2][6 + a] = 1;
            Matriz1[3][1 + a] = 1;
            Matriz1[3][2 + a] = 1;
            Matriz1[3][3 + a] = 1;
            Matriz1[3][4 + a] = 1;
            Matriz1[3][5 + a] = 1;
            Matriz1[3][6 + a] = 1;
            Matriz1[3][7 + a] = 1;
            Matriz1[4][1 + a] = 1;
            Matriz1[4][7 + a] = 1;
            Matriz1[5][1 + a] = 1;
            Matriz1[5][7 + a] = 1;
            Matriz1[6][1 + a] = 1;
            Matriz1[6][2 + a] = 1;
            Matriz1[6][6 + a] = 1;
            Matriz1[6][7 + a] = 1;
            Matriz1[7][2 + a] = 1;
            Matriz1[7][6 + a] = 1;
            Mostrar();
            Reiniciar();
            System.out.println("\n");
        }

    }

    public void RecorridoI() {
        for (int a = 0; a < 8; a++) {
            Matriz1[3][1 + a] = 1;
            Matriz1[3][7 + a] = 1;
            Matriz1[4][1 + a] = 1;
            Matriz1[4][2 + a] = 1;
            Matriz1[4][3 + a] = 1;
            Matriz1[4][4 + a] = 1;
            Matriz1[4][5 + a] = 1;
            Matriz1[4][6 + a] = 1;
            Matriz1[4][7 + a] = 1;
            Matriz1[5][1 + a] = 1;
            Matriz1[5][2 + a] = 1;
            Matriz1[5][3 + a] = 1;
            Matriz1[5][4 + a] = 1;
            Matriz1[5][5 + a] = 1;
            Matriz1[5][6 + a] = 1;
            Matriz1[5][7 + a] = 1;
            Matriz1[6][1 + a] = 1;
            Matriz1[6][7 + a] = 1;
            Mostrar();
            Reiniciar();
            System.out.println("\n");
        }

    }

    public void RecorridoO() {
        for (int a = 0; a < 8; a++) {
            Matriz1[2][2 + a] = 1;
            Matriz1[2][3 + a] = 1;
            Matriz1[2][4 + a] = 1;
            Matriz1[2][5 + a] = 1;
            Matriz1[2][6 + a] = 1;
            Matriz1[3][1 + a] = 1;
            Matriz1[3][2 + a] = 1;
            Matriz1[3][3 + a] = 1;
            Matriz1[3][4 + a] = 1;
            Matriz1[3][5 + a] = 1;
            Matriz1[3][6 + a] = 1;
            Matriz1[3][7 + a] = 1;
            Matriz1[4][1 + a] = 1;
            Matriz1[4][7 + a] = 1;
            Matriz1[5][1 + a] = 1;
            Matriz1[5][7 + a] = 1;
            Matriz1[6][1 + a] = 1;
            Matriz1[6][2 + a] = 1;
            Matriz1[6][3 + a] = 1;
            Matriz1[6][4 + a] = 1;
            Matriz1[6][5 + a] = 1;
            Matriz1[6][6 + a] = 1;
            Matriz1[6][7 + a] = 1;
            Matriz1[7][2 + a] = 1;
            Matriz1[7][3 + a] = 1;
            Matriz1[7][4 + a] = 1;
            Matriz1[7][5 + a] = 1;
            Matriz1[7][6 + a] = 1;
            Mostrar();
            Reiniciar();
            System.out.println("\n");
        }
    }

    public void Reiniciar() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 15; j++) {
                Matriz1[i][j] = 0;
            }
        }
    }

    public void Mostrar() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 15; j++) {
                System.out.print(Matriz1[i][j]);
            }
            System.out.print("\n");
        }

    }
}
