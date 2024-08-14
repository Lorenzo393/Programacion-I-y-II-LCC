;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname |Practica 4 - 5|) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require 2htdp/universe)
(require racket/base)
(require test-engine/racket-tests)

;Ej 5
(define CIRCULO (circle 20 "solid" "red"))
(define ESCENA (empty-scene 300 300))
(define INICIAL (make-posn 150 150))


(define (pantalla p)
  (place-image CIRCULO
               (posn-x p) (posn-y p)
               ESCENA))

(define (teclado p k)
  (cond [(string=? "up" k) (make-posn (posn-x p) (- (posn-y p) 20))]
        [(string=? "down" k) (make-posn (posn-x p) (+ (posn-y p) 20))]
        [(string=? "right" k) (make-posn (+ (posn-x p) 20) (posn-y p))]
        [(string=? "left" k) (make-posn (- (posn-x p) 20) (posn-y p))]))

(define (mouse p x y event)
  (cond [(string=? event "button-down") (make-posn x y)]
        [else p]))

(big-bang INICIAL
  [to-draw pantalla]
  [on-key teclado]
  [on-mouse mouse])