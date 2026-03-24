# Práctica de Laboratorio: AES y Modos de Operación sobre Imágenes BMP

## 🎯 Objetivo General
Comprender de forma visual y práctica cómo funcionan los modos de operación criptográfica ECB, CBC y CTR al aplicarse directamente sobre los datos de una imagen en formato BMP.

## 🏗 Arquitectura del Proyecto

El flujo de ejecución del notebook está estructurado en las siguientes fases lógicas:

1. **Manipulación de Archivos BMP:** Separa la cabecera del archivo (los primeros 54 bytes) del cuerpo de la imagen para cifrar únicamente los píxeles y preservar la estructura que permite al sistema operativo renderizar el archivo.
2. **Gestión del Estado Criptográfico:** Delegación de la entropía al sistema operativo para generar llaves seguras (16 bytes), Vectores de Inicialización (16 bytes) y Nonces (8 bytes). Este estado se persiste en un archivo JSON local (`mis_claves_MATRICULA.json`).
3. **Pipeline de Cifrado y Descifrado:** Implementación de un enrutador que procesa la imagen a través de los modos ECB, CBC y CTR.
4. **Tolerancia a Fallos (Bit-Flipping):** Simulación de corrupción de datos en tránsito alterando un byte específico (posición 2000) en los archivos cifrados para analizar visualmente la propagación de errores en cada modo de operación.
5. **Pruebas de Intercambio (Peer Testing):** Validación del principio fundamental de que la seguridad recae en la llave probando el descifrado cruzado con material criptográfico de un compañero.

##  Requisitos y Dependencias

Para ejecutar este entorno de laboratorio, se requieren las siguientes librerías:

* `pycryptodome`: Para las primitivas de AES y generación de bytes aleatorios.
* `Pillow (PIL)` e `IPython`: Para el renderizado en memoria y la visualización de las imágenes directamente en las celdas del notebook.

**Instalación:**
```bash
pip install pycryptodome pillow ipython