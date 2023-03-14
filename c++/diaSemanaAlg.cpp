#include <iostream>
#include <string>
using namespace std;

bool esBisiesto(unsigned agno) {
    bool multiplo4   = (agno % 4 == 0);
    bool multiplo100 = (agno % 100 == 0);
    bool multiplo400 = (agno % 400 == 0);
    return multiplo400 || (multiplo4 && !multiplo100);
}

unsigned diasDelMes(unsigned mes, unsigned agno) {
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        return 31;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    }
    else if (mes == 2) {
        if (esBisiesto(agno)) {
            return 29;
        }
        else {
            return 28;
        }
    }
}

void recogerDatos(int& ax, int& bx, int& cx, int& dx, int& ex, unsigned dia, unsigned mes, unsigned agno) {
    if (agno >= 1700 && agno <= 1799) {
        ax = 5;
    }
    else if (agno >= 1800 && agno <= 1899) {
        ax = 3;
    }
    else if (agno >= 1900 && agno <= 1999) {
        ax = 1;
    }
    else if (agno >= 2000 && agno <= 2099) {
        ax = 0;
    }
    else if (agno >= 2100 && agno <= 2199) {
        ax = -2;
    }
    else if (agno >= 2200 && agno <= 2299) {
        ax = -4;
    }

    bx = ((agno % 100) / 4) + (agno % 100);

    if (esBisiesto(agno) && mes == 1 || esBisiesto(agno) && mes == 2) {
        cx = (-1);
    }
    else {
        cx = 0;
    }

    if (mes == 1 || mes == 10) {
        dx = 6;
    }
    else if (mes == 2 || mes == 3 || mes == 11) {
        dx = 2;
    }
    else if (mes == 4 || mes == 7) {
        dx = 5;
    }
    else if (mes == 5) {
        dx = 0;
    }
    else if (mes == 6) {
        dx = 3;
    }
    else if (mes == 8) {
        dx = 1;
    }
    else if (mes == 9 || mes == 12) {
        dx = 4;
    }

    ex = dia;
}

void sumarCoeficientes(int& codigo, int ax, int bx, int cx, int dx, int ex) {
    codigo = (ax + bx + cx + dx + ex) % 7;
}

void escribirMes (unsigned mes) {
    const string NOMBRE_MES[12] = {"enero","febrero","marzo", "abril", "mayo",
    "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
    cout << NOMBRE_MES[mes - 1];
}

void escribirDia(int codigo) {
    const string NOMBRE_DIA[7] = {"domingo", "lunes", "martes", "miercoles", "jueves",
    "viernes", "sabado"};
    cout << NOMBRE_DIA[codigo] << "." << endl;
}

void escribirResultado(unsigned dia, unsigned mes, unsigned agno, int codigo) {
    cout << "El dia " << dia << " de ";
    escribirMes(mes);
    cout << " de " << agno << " es ";
    escribirDia(codigo);
}

int main () {
    unsigned dia = 1;
    unsigned mes, agno;
    int ax, bx, cx, dx, ex, codigo;

    system("cls");
    while (dia != 0) {
        cout << "Escriba una fecha comprendida entre 1700 y 2299 (0 para cancelar): ";
        cin >> dia;
        if (dia == 0) {
            return 0;
        }
        cin >> mes >> agno;

        while(dia < 0 || dia > diasDelMes(mes, agno) || mes < 1 || mes > 12 || agno < 1700 || agno > 2299) {
            cout << "Escriba un formato de fecha valido (0 para cancelar): ";
            cin >> dia;
            
            if (dia == 0) {
                return 0;
            }

            cin >> mes >> agno;
        }

        recogerDatos(ax, bx, cx, dx, ex, dia, mes, agno);
        sumarCoeficientes(codigo, ax, bx, cx, dx, ex);
        escribirResultado(dia, mes, agno, codigo);
    }

    return 0;
}