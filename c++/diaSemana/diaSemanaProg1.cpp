#include <iostream>
using namespace std;

bool esBisiesto(const unsigned agno) {
    bool multiplo4   = (agno % 4 == 0);
    bool multiplo100 = (agno % 100 == 0);
    bool multiplo400 = (agno % 400 == 0);
    return multiplo400 || (multiplo4 && !multiplo100);
}

unsigned diasDelMes(const unsigned mes, const unsigned agno) {
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

unsigned agnosBisiestos(unsigned agno) {
    unsigned i = 0;
    while (agno > 1703) {
        agno--;
        if (esBisiesto(agno)) {
            i++;
        }
    }
    return i;
}

unsigned diasAgnos(const unsigned agno) {
    return ((agno - 1703 - agnosBisiestos(agno)) * 365) + (agnosBisiestos(agno) * 366) - 1;
}

unsigned diaEnElAgno(const unsigned dia, const unsigned mes, const unsigned agno) {
    if (mes == 1) {
        return dia;
    }
    else if (mes == 2) {
        return 31 + dia;
    }
    else if (mes == 3) {
        if (esBisiesto(agno)) {
            return 31 + 29 + dia;
        }
        else {
            return 31 + 28 + dia;
        }
    }
    else if (mes == 4) {
        if (esBisiesto(agno)) {
            return 31 + 29 + 31 + dia;
        }
        else {
            return 31 + 28 + 31 + dia;
        }
    }
    else if (mes == 5) {
        if (esBisiesto(agno)) {
            return 31 + 29 + 31 + 30 + dia;
        }
        else {
            return 31 + 28 + 31 + 30 + dia;
        }
    }
    else if (mes == 6) {
        if (esBisiesto(agno)) {
            return 31 + 29 + 31 + 30 + 31 + dia;
        }
        else {
            return 31 + 28 + 31 + 30 + 31 + dia;
        }
    }
    else if (mes == 7) {
        if (esBisiesto(agno)) {
            return 31 + 29 + 31 + 30 + 31 + 30 + dia;
        }
        else {
            return 31 + 28 + 31 + 30 + 31 + 30 + dia;
        }
    }
    else if (mes == 8) {
        if (esBisiesto(agno)) {
            return 31 + 29 + 31 + 30 + 31 + 30 + 31 + dia;
        }
        else {
            return 31 + 28 + 31 + 30 + 31 + 30 + 31 + dia;
        }
    }
    else if (mes == 9) {
        if (esBisiesto(agno)) {
            return 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + dia;
        }
        else {
            return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + dia;
        }
    }
    else if (mes == 10) {
        if (esBisiesto(agno)) {
            return 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + dia;
        }
        else {
            return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + dia;
        }
    }
    else if (mes == 11) {
        if (esBisiesto(agno)) {
            return 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + dia;
        }
        else {
            return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + dia;
        }
    }
    else if (mes == 12) {
        if (esBisiesto(agno)) {
            return 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + dia;
        }
        else {
            return 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + dia;
        }
    }
}

void diaDeLaSemana(const unsigned dia, const unsigned mes, const unsigned agno, unsigned& codigodia) {
    unsigned diastotales = 0;
    
    if (agno == 1703) {
        diastotales = diasAgnos(agno) + diaEnElAgno(dia, mes, agno);
    }
    else if (agno > 1703) {
        diastotales = diasAgnos(agno) + diaEnElAgno(dia, mes, agno);
    }
    codigodia = diastotales % 7;
}

void escribirMes (const unsigned mes) {
    const string NOMBRE_MES[12] = {"enero","febrero","marzo", "abril", "mayo",
    "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
    cout << NOMBRE_MES[mes - 1];
}

void escribirDia(const unsigned codigodia) {
    const string NOMBRE_DIA[7] = {"lunes", "martes", "miercoles", "jueves",
    "viernes", "sabado", "domingo"};
    cout << NOMBRE_DIA[codigodia] << "." << endl;
}

void escribirFecha(const unsigned dia, const unsigned mes, const unsigned agno, const unsigned codigodia) {
    cout << "El dia " << dia << " de ";
    escribirMes(mes);
    cout << " de " << agno << " es ";
    escribirDia(codigodia);
    cout << endl;
}

int main () {
    unsigned mes, agno, codigodia;
    unsigned dia = 1;
    system("cls");

    while (dia != 0) {
        cout << "Escriba una fecha entre 1703 y 4294967295 (0 para cancelar): ";
        cin >> dia;
        if (dia == 0) {
            return 0;
        }
        cin >> mes >> agno;

        while(dia < 0 || dia > diasDelMes(mes, agno) || mes < 1 || mes > 12 || agno < 1703) {
            cout << "Escriba un formato de fecha valido (0 para cancelar): ";
            cin >> dia >> mes >> agno;

            if (dia == 0) {
                return 0;
            }
        }
        diaDeLaSemana (dia, mes, agno, codigodia);
        escribirFecha(dia, mes, agno, codigodia);
    }
    return 0;
}