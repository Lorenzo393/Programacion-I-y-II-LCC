;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname |Practica 4 - 11|) (read-case-sensitive #t) (teachpacks ((lib "image.rkt" "teachpack" "2htdp") (lib "universe.rkt" "teachpack" "2htdp"))) (htdp-settings #(#t constructor repeating-decimal #f #t none #f ((lib "image.rkt" "teachpack" "2htdp") (lib "universe.rkt" "teachpack" "2htdp")) #f)))
(require 2htdp/image)
(require 2htdp/universe)
(require racket/base)
(require test-engine/racket-tests)

;Ej 12
(define-struct Casa[dueño dire sup zona])
; Casa: String, String, Number, String
; Casa: Dueño , Direccion, SuperficeM2, Zona

(define VAL-A 20000)
(define VAL-B 15000)
(define VAL-C 10000)
(define VAL-D 5000)

(define (valor-bruto s z)
  (cond [(string=? z "A") (* s VAL-A)]
        [(string=? z "B") (* s VAL-B)]
        [(string=? z "C") (* s VAL-C)]
        [(string=? z "D") (* s VAL-D)]))

(define (sellado v)
  (cond [(>= v 1000000) (* v 0.95)]
        [else (* v 0.97)]))

(define (zona z)
  (cond [(string=? z "A") #t]
        [(string=? z "B") #t]
        [(string=? z "C") #t]
        [(string=? z "D") #t]
        [else #f]))

(define (venta c)
  (cond [(zona (Casa-zona c)) (string-append (Casa-dueño c) " recibirá " (number->string (sellado (valor-bruto (Casa-sup c) (Casa-zona c)))) " por la venta de su propiedad ubicada en " (Casa-dire c))]
        [else "No se puede calcular el precio de venta por no disponer de los valores del metro cuadrado para la zona solicitada"]))