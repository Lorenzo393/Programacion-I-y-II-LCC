;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname |Práctica 4|) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require 2htdp/universe)
(require racket/base)
(require test-engine/racket-tests)

;PRACTICA 4
;Ej 1
(define p (make-posn 3 4))
(define q (make-posn -2 0.5))

(posn-x p)
(- (posn-y p) (posn-y q))
(posn-y (make-posn (posn-x p) (posn-x q)))

;Ej 2
(define (modulo xy)
  (sqrt(+ (sqr(posn-x xy)) (sqr (posn-y xy)))))

(modulo (make-posn (/ 6 2) 4))
(+ (modulo (make-posn 12 5)) 4)

;Ej 3
(define (simetrica xy)
  (make-posn (posn-y xy) (posn-x xy)))

;Ej 4
(define (distancia p1 p2)
  (cond [(and (posn? p1) (posn? p2)) (modulo (vector-origen p1 p2))]
        [else "Tipos incorrectos para la funcion"]))

(define (vector-origen p1 p2)
  (make-posn (- (posn-x p2) (posn-x p1)) (-(posn-y p2) (posn-y p1))))