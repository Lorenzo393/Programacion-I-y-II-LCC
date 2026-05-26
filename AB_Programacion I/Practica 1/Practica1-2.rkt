;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname Practica1-2) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require racket/base)
;Practica 1 parte 2

;CALCULANDO CON EXPRESIONES COND
;Ej 1
(define (sgn2 x) (cond [(< x 0) -1]
                       [(= x 0) 0]
                       [(> x 0) 1]))

(sgn2 (- 2 3))
(sgn2 6)

;Ej 2 - 2,4,6,7
(define (clas-img x)
  (cond [(< (image-width x) (image-height x)) "Angosta"]
        [(> (image-width x) (image-height x)) "Ancha"]
        [else "Cuadrada"]))

(define (ang x y z)
  (cond [(not (= (+ x y z) 180)) "No es triangulo"]
        [(= x y z) "Equilatero"]
        [(= x y) "Isosceles"]
        [(= x z) "Isosceles"]
        [(= y z) "Isosceles"]
        [else "Escaleno"]))

(define PC 60)
(define PL 8)
(define (precio c l)
  (cond [(>= (+ c l) 10) (+ (* l PL 0.82) (* c PC 0.82))]
        [(and (>= l 5) (>= c 4)) (+ (* l PL 0.85) (* c PC 0.90))]
        [(>= l 5) (+ (* l PL 0.85) (* c PC))]
        [(>= c 4) (+ (* l PL) (* c PC 0.90))]
        [else (+ (* l PL) (* c PC))]))

(define (pitagorica? a b c)
  (cond [(= (+ (sqr a) (sqr b)) (sqr c)) #t]
        [else #f]))


(define (pitagoricastr? a b c)
  (cond [(= (+ (sqr a) (sqr b)) (sqr c)) (string-append "Los numeros " (number->string a)
      ", "(number->string b) " y " (number->string c) " forman una terna pitagorica")]
        [else (string-append "Los numeros " (number->string a)
      ", "(number->string b) " y " (number->string c) " no forman una terna pitagorica")]))

;Ej 3
(pitagorica? 3 5 6)
(pitagorica? 3 5 4)

;Ej 4
(define (clas-img2 x)
  (cond [(< (* 2 (image-width x)) (image-height x)) "Muy angosta"]
        [(< (image-width x) (image-height x)) "Angosta"]
        [(> (image-width x) (* 2 (image-height x))) "Muy Ancha"]
        [(> (image-width x) (image-height x)) "Ancha"]
        [else "Cuadrada"]))

;Ej 5
(define (clasificar t)
  (cond [(< t 0) "Muy frío (MF)"]
        [(and (>= t 0) (< t 15)) "Frío (F)"]
        [(and (>= t 15) (< t 25)) "Agradable (A)"]
        [(>= t 25) "Caluroso (C)"]))

(clasificar -3)
(clasificar 12)
(clasificar 15)
(clasificar 28)

; PREDICADOS
(string? "23")
(number? -4)
(real? 1.2)
(boolean? #t)

(define (sgn3 x)
  (cond [(number? x) (sgn2 x)]
        [(string? x) (sgn2 (string->number x))]))

;Ej 6 ???
(define (sgnbl x)
  (cond [(number? x) (sgn x)]
        [x (sgn 1)]
        [(not x) (sgn 0)]))

;Ej 7
(define (sgnimg x)
  (cond [(number? x) (sgn x)]
        [(image? x) (cond [(string=? (clas-img x) "Ancha") (sgn 1)]
                          [(string=? (clas-img x) "Angosta") (sgn -1)]
                          [(string=? (clas-img x) "Cuadrada") (sgn 0)])]))

;Ej 8 y 9
(define (sgnult x)
  (cond [(number? x) (sgn x)]
        [(boolean? x) (sgnbl x)]
        [(image? x) (cond [(string=? (clas-img x) "Ancha") (sgn 1)]
                          [(string=? (clas-img x) "Angosta") (sgn -1)]
                          [(string=? (clas-img x) "Cuadrada") (sgn 0)])]
        [(string? x) (cond [(number? (string->number x)) (sgn (string->number x))]
                           [else "La cadena no se puede convertir a un numero"])]
        [else "Clase no soportada por la funcion"]))