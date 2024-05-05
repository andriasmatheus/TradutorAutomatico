import sys
from googletrans import Translator

linguagemSrc = 'pt'

linguagensDest = ['en', 'es']  # Lista em vez de conjunto

def translate_word(word, lingua):
    translator = Translator()
    translated = translator.translate(word, src=linguagemSrc, dest=lingua)
    return translated.text

if __name__ == "__main__":
    # Verificar se o número correto de argumentos foi fornecido
    if len(sys.argv) != 3:
        print("Uso: python programa.py palavra linguagem_destino")
        sys.exit(1)

    # Argumentos da linha de comando
    word_to_translate = sys.argv[1]
    linguagem_destino = sys.argv[2]

    # Verificar se a linguagem de destino é válida
    if linguagem_destino not in linguagensDest:
        print("Linguagem de destino inválida. Escolha entre 'en' ou 'es'.")
        sys.exit(1)

    # Traduzir a palavra
    translated_word = translate_word(word_to_translate, linguagem_destino)
    print(f"Tradução para {linguagem_destino}: {translated_word}")