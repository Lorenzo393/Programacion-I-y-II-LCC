;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname |Pracitca 4 - 10|) (read-case-sensitive #t) (teachpacks ((lib "image.rkt" "teachpack" "2htdp") (lib "universe.rkt" "teachpack" "2htdp"))) (htdp-settings #(#t constructor repeating-decimal #f #t none #f ((lib "image.rkt" "teachpack" "2htdp") (lib "universe.rkt" "teachpack" "2htdp")) #f)))
(require 2htdp/image)
(require 2htdp/universe)
(require racket/base)
(require test-engine/racket-tests)

;Ej 10
(define-struct Auto[mdl año cmbs kpl])
; Auto: String, Number, String, Number
; Auto: Modelo, Año, Combustible, kilometros/litro

(define COSTEPEAJE 50)
(define COSTENAFTA 19)
(define COSTEDIESEL 17)
(define DIST-PEAJE 100)

(define (rendimiento a kpl)
  (cond [(and (>= a 1) (<= a 5)) (* kpl 0.98)]
        [(and (> a 5) (<= a 10)) (* kpl 0.94)]
        [(and (> a 10) (<= a 15)) (* kpl 0.90)]
        [(> a 15) (* kpl 0.85)]
        [else kpl]))

(define (precio-litro l cmbs)
  (cond [(string=? cmbs "nafta") (* l COSTENAFTA)]
        [(string=? cmbs "diesel") (* l COSTEDIESEL)]))

(define (peajes m)
  (cond [(>= m DIST-PEAJE) (* (quotient m DIST-PEAJE) COSTEPEAJE)]))

(define (costo-viaje a m)
  (+ (peajes m) (precio-litro (/ m (rendimiento (Auto-año a) (Auto-kpl a))) (Auto-cmbs a))))