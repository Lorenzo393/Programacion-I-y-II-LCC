;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname Practica1-2) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require racket/base)
;Practica 1 parte 2

;CALCULANDO CON EXPRESIONES COND
(define (sgn2 x) (cond [(< x 0) -1]
                       [(= x 0) 0]
                       [(> x 0) 1]))
;Ej 1
(sgn2 (- 2 3))
(sgn2 6)
;Ej 2
(define (clasificator x)
  (cond ([(= (image-width x) (image-height x)) "Cuadrada"]
       [(< (image-width x) (image-height x)) "Angosta"]
       [(> (image-width x) (image-height x)) "Ancha"])))

