// Librerías necesarias
#include <stdio.h>     // Para printf() y scanf_s()
#include <stdlib.h>   // Para system("pause")
#include <locale.h>  // Para configuración regional UTF-8 en sistemas UNIX (Distribuciones de Linux, MacOS y Solaris).

// Configuración especial para Windows
#ifdef _WIN32
#include <windows.h>    // Para funciones de la API de Windows.
#endif

// Configuración UTF-8 compatible con Dev-C++.
void configure_encoding() {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
        system("chcp 65001 > nul"); // UTF-8 en consola de Dev-C++
    #else
        setlocale(LC_ALL, "C.UTF-8");
    #endif
}

// Constantes con los rangos de puntajes
#define MIN_SOFTWARE 100
#define MIN_LOGISTICA 90
#define MAX_LOGISTICA 99
#define MIN_TELEMATICA 80
#define MAX_TELEMATICA 89
#define MIN_MATEMATICAS 70
#define MAX_MATEMATICAS 79
#define PUNTAJE_MINIMO 70

int main() {
	configure_encoding();
	
	// Datos del estudiante y caratula:
	printf("*************************************************************\n");
	printf("***Fundamentos de la programación U2 Evidencia de aprendizaje***\n");
	printf("Estudiante: Orlando Antonio Maturano Pizaña.\n");
	printf("Matrícula: ES251107915.\n");
	printf("Grupo: DS-DFPR-2501-B1-013.\n");
	printf("*************************************************************\n");
	printf("");
	
	// Variables del programa:
	int opcion, puntaje;
	
	// Blucle principal
	do {
		// Mostrar el menú principal de opciones:
		printf("*****************************************\n");
		printf("   Introduce la opción deseada: \n");
		printf("   (1) Ingresar puntaje del estudiante.\n");
		printf("   (2) Salir del programa.\n");
		scanf_s("%d", &opcion);
		
		// Procesar opción seleccionada:
		switch (opcion) {
			case 1:   // Evaluar puntaje
			    printf("\nIntroduce el puntaje: ");
			    scanf_s("%d", &puntaje);
			    
			    // Evaluar rango del puntaje
			    if (puntaje >= MIN_SOFTWARE) {
			    	printf("Carrera asignada: Ingeniería en Desarrollo de Software.\n\n");
				} else if (puntaje >= MIN_LOGISTICA && puntaje <= MAX_LOGISTICA) {
					printf("Carrera asignada: Ingeniería en Logística y Transporte.\n\n");
				} else if (puntaje >= MIN_TELEMATICA && puntaje <= MAX_TELEMATICA) {
					printf("Carrera asignada: Ingeniería en Telemática.\n\n");
				} else if (puntaje >= MIN_MATEMATICAS && puntaje <= MAX_MATEMATICAS) {
					printf("Carrera asignada: Licenciatura en Enseñanza de las Matemáticas.\n\n");
				} else if (puntaje < PUNTAJE_MINIMO) {
					printf("El puntaje no es adecuado para cursar una carrera en la UnADM\n\n");
				}
				break;
				
			case 2:    // Salir del programa.
			    break;
			    
		    default:  // Opción no válida.
		    	printf("\n¡Error! Opción no válida\n\n");
		}
	} while (opcion !=2);   // Repetir hasta que se elija «Salir».
	
	// Pusar antes de cerrar (Solo para Windows):
	#ifdef _WIN32
	system("pause");
	#endif
	
	return 0;
	}