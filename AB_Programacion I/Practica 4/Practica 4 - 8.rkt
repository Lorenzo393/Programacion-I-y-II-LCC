;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname |Practica 4 - 8|) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require 2htdp/universe)
(require racket/base)
(require test-engine/racket-tests)

;Ej 8
(define-struct Texto [xs color tam])
; Texto: (String, Color, Number)

(define ESCENA (empty-scene 700 700))
(define INICIAL (Texto "" "red" 30))
(define MIN-TAMAÑO 10)
(define MAX-TAMAÑO 100)
(define TAMAÑO 2)


(define (pantalla t)
  (place-image/align (text (Texto-xs t) (Texto-tam t) (Texto-color t))
                     (/ (image-width ESCENA) 2) (/ (image-height ESCENA) 2) "center" "center"
                     ESCENA))

(define (teclado t k)
  (cond [(string=? k "up") (cond [(< (Texto-tam t) MAX-TAMAÑO) (Texto (Texto-xs t) (Texto-color t) (+ (Texto-tam t) TAMAÑO))]
                                 [else t])]
        [(string=? k "down") (cond [(> (Texto-tam t) MIN-TAMAÑO) (Texto (Texto-xs t) (Texto-color t) (- (Texto-tam t) TAMAÑO))]
                                   [else t])]
        [(string=? k "f1") (Texto (Texto-xs t) "red" (Texto-tam t))]
        [(string=? k "f2") (Texto (Texto-xs t) "blue" (Texto-tam t))]
        [(string=? k "f3") (Texto (Texto-xs t) "green" (Texto-tam t))]
        [(string=? k "f4") (Texto (Texto-xs t) "black" (Texto-tam t))]
        [(string=? k "f5") (Texto (Texto-xs t) "yellow" (Texto-tam t))]
        [(string=? k "f6") (Texto (Texto-xs t) "brown" (Texto-tam t))]
        [(string=? k "\b") (cond [(> (string-length (Texto-xs t)) 0) (Texto (substring (Texto-xs t) 0 (- (string-length (Texto-xs t)) 1)) (Texto-color t) (Texto-tam t))]
                                 [else t])]
        [else (Texto (string-append (Texto-xs t) k) (Texto-color t) (Texto-tam t))]))

(big-bang INICIAL
  [to-draw pantalla]
  [on-key teclado])