;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-reader.ss" "lang")((modname |Practica 6|) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require 2htdp/universe)
(require racket/base)
(require test-engine/racket-tests)

; Fabricar listas

(define-struct Diablo [dia  blo])
; Naturales
; 0
; add1
; sub1
; zero?
; positive?

;Ej 1

(define (sumanat n1 n2)
  (cond [(zero? n2) n1]
        [(positive? n2) (sumanat (add1 n1) (sub1 n2))]))

(sumanat 7 3)

;(check-expect (sumanat 7 3) 10)
;(check-expect (sumanat 3 0) 3)

;Ej 2

(define (multnat n1 n2)
  (cond [(zero? n2) 0]
        [(positive? n2) (sumanat n1 (multnat n1 (sub1 n2)))]))

;Ej 3

(define (powernat n1 n2)
  (cond [(zero? n2) 1]
        [(positive? n2) (multnat n1 (powernat n1 (sub1 n2)))]))


; Ej 9
(define (intervalo n)
  (cond [(zero? n) (list 0)]
        [else  (cons n (intervalo (sub1 n)))]))





