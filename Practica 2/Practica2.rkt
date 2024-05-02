;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname Practica2) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require racket/base)
(require test-engine/racket-tests)

; DISEÑEMOS FUNCIONES SIMPLES

;Ej 1
; Representa distancias mediante numeros
; Mediante 2 coordenadas x y, calcula la distancia al origen
; dist-origen: Number Number -> Number
; entrada: 4 3 - salida: 5
; entrada: 0 0 - salida: 0
(define (dist-origen x y)
  (sqrt (+ (sqr x) (sqr y))))

(check-expect (dist-origen 4 3) 5)
(check-expect (dist-origen 0 0) 0)

;Ej 2
; Representa distancias mediante numeros
; Mediante 4 coordenadas x y, calcula la distancia entre ellos
; dist-puntos: Number Number Number Number -> Number
; entrada: 3 4 0 0 - salida: 5
; entrada: 0 0 3 4 - salida: 5
(define (dist-puntos x1 y1 x2 y2)
  (dist-origen (- x2 x1) (- y2 y1)))

(check-expect (dist-puntos 3 4 0 0) 5)
(check-expect (dist-puntos 0 0 3 4) 5)

;Ej 3
; Representa distancias mediante numeros
; Mediante el lado de un cubo calcula su volumen
; vol-cubo: Number -> Number
; entrada: 3 - salida: 9
; entrada: 0 - salida: 0
(define (vol-cubo x)
  (* x x x))

(check-expect (vol-cubo 3) 27)
(check-expect (vol-cubo 0) 0)

;Ej 4
; Represento longitudes mediante numeros
; Mediante el lado de un cubo calculo el area de una cara
; area-cubo: Number -> Number
; entrada: 3 - salida: 9
; entrada: 0 - salida: 0
(define (area-cubo x)
  (sqr x))

(check-expect (area-cubo 3) 9)
(check-expect (area-cubo 0) 0)

;Ej 5
; Con un string y un numero i, inserta "-" en la posicion i
; string-insert: String Number -> String
; entrada: "HolaMundo" 4 - salida: Hola-Mundo
; entrada: "" 0 - "-"

(define (string-insert xs n)
  (string-append (substring xs 0 n) "-" (substring xs n (string-length xs))))

(check-expect (string-insert "HolaMundo" 4) "Hola-Mundo")
(check-expect (string-insert "" 0) "-")

;Ej 6
; Devuelve el ultimo caracter de una cadena no vacia
; string-last: String -> String
; entrada: diablo - salida: o
; entrada: " " - salida: " "
(define (string-last xs)
  (substring xs (- (string-length xs) 1) (string-length xs)))

(check-expect (string-last "diablo") "o")
(check-expect (string-last " ") " ")

; Ej 7
; Devuelve la cadena sin el ultimo caracter
; string-remove-last: String -> String
; entrada: "diablo" - salida: "diabl"
; entrada: " " - salida: ""
(define (string-remove-last xs)
  (substring xs 0 (- (string-length xs) 1)))

(check-expect (string-remove-last "diablo") "diabl")
(check-expect (string-remove-last " ") "")

;Ej 9
; Dadas cantidad de personas y cantidad de meses que abonan calcula el monto a pagar
; monto-persona: Number Number -> Number
; entrada: - salida:
; entrada: - salida:
(define VC 650)

(define (monto-persona n m)
  (cond [(and (>= n 3) (>= m 2)) (* VC n m 0.65)]
        [(and (>= n 2) (>= m 2)) (* VC n m 0.75)]
        [(>= n 3) (* VC n m 0.80)]
        [(>= n 2) (* VC n m 0.90)]
        [(>= m 2) (* VC n m 0.85)]))

;(check-expect (monto-persona 3 2))




























