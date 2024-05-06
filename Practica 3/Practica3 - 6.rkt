;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname |Practica3 - 6|) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require 2htdp/universe)
(require racket/base)
(require test-engine/racket-tests)

;PROGRAMAS INTERACTIVOS
;Ej 6

(define INICIAL "")
(define FONDO (empty-scene 300 300))
(define XTEXT 150)
(define YTEXT 150)

(define (pantalla xs)
  (place-image/align (text xs 20 "indigo")
                   XTEXT YTEXT "center" "center"
                   FONDO))

(define (teclado xs t)
  (cond [(string=? "\b" t) (cond [(= (string-length xs) 0) xs]
                               [else (substring xs 0 (- (string-length xs) 1))])]
        [else (string-append xs t)]))

(big-bang INICIAL
  [to-draw pantalla]
  [on-key teclado])