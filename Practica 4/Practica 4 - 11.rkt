;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname |Practica 4 - 11|) (read-case-sensitive #t) (teachpacks ((lib "image.rkt" "teachpack" "2htdp") (lib "universe.rkt" "teachpack" "2htdp"))) (htdp-settings #(#t constructor repeating-decimal #f #t none #f ((lib "image.rkt" "teachpack" "2htdp") (lib "universe.rkt" "teachpack" "2htdp")) #f)))
(require 2htdp/image)
(require 2htdp/universe)
(require racket/base)
(require test-engine/racket-tests)

;Ej 11
(define-struct Alumno[nombre prom asist])
; Alumno: String, Number, Number
; Alumno: Nombre, Promedio, Asistencia

(define (condicion a)
  (cond [(Alumno? a) (cond [(and (>= (Alumno-prom a) 8) (>= (Alumno-asist a) 60)) (string-append (Alumno-nombre a) ": promovido")]
        [(and (>= (Alumno-prom a) 6) (>= (Alumno-asist a) 60)) (string-append (Alumno-nombre a) ": regular")]
        [else (string-append (Alumno-nombre a) ": libre")])]
        [else "Tipo de dato no valido"]))