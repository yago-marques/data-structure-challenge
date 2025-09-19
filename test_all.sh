#!/bin/bash

# Script de teste completo para Data Structure Challenger
# Este script compila e testa todos os níveis do Detective Quest

echo "🎮 =================================================="
echo "   DATA STRUCTURE CHALLENGER - TESTE COMPLETO"
echo "🎮 =================================================="
echo ""

# Função para testar um nível
test_level() {
    local level=$1
    local description=$2
    local executable=$3
    
    echo "🔹 Testando $level - $description"
    echo "   ────────────────────────────────────────────"
    
    cd "$level" || { echo "❌ Erro: Diretório $level não encontrado"; return 1; }
    
    # Compila o programa
    echo "   🔨 Compilando..."
    if make clean > /dev/null 2>&1 && make > /dev/null 2>&1; then
        echo "   ✅ Compilação bem-sucedida"
        
        # Verifica se o executável foi criado
        if [ -f "$executable" ]; then
            echo "   ✅ Executável '$executable' criado"
            echo "   📏 Tamanho: $(ls -lh $executable | awk '{print $5}')"
            echo "   🎯 Para executar: cd $level && ./$executable"
        else
            echo "   ❌ Executável não foi criado"
        fi
    else
        echo "   ❌ Erro na compilação"
        echo "   🔍 Executando make com detalhes..."
        make
    fi
    
    echo ""
    cd .. || exit 1
}

# Verifica se estamos no diretório correto
if [ ! -f "README.md" ] || [ ! -d "novato" ]; then
    echo "❌ Erro: Execute este script na raiz do projeto data-structure-challenger"
    exit 1
fi

echo "📍 Diretório atual: $(pwd)"
echo "📋 Níveis encontrados: $(ls -d */ | tr '\n' ' ')"
echo ""

# Testa cada nível
test_level "novato" "Fundamentos com Árvore Binária" "detective_quest"
test_level "aventureiro" "Coleta de Pistas com BST" "detective_quest_pistas"
test_level "mestre" "Sistema Completo com Hash Table" "detective_quest_mestre"

echo "🏆 =================================================="
echo "   RESUMO DOS TESTES"
echo "🏆 =================================================="
echo ""

# Verifica quais executáveis foram criados
echo "📊 Status dos executáveis:"
for level in novato aventureiro mestre; do
    cd "$level" || continue
    case $level in
        "novato")
            executable="detective_quest"
            ;;
        "aventureiro") 
            executable="detective_quest_pistas"
            ;;
        "mestre")
            executable="detective_quest_mestre"
            ;;
    esac
    
    if [ -f "$executable" ]; then
        echo "   ✅ $level/$executable - OK"
    else
        echo "   ❌ $level/$executable - FALHOU"
    fi
    cd .. || exit 1
done

echo ""
echo "🎯 COMO JOGAR:"
echo "   1. Novato:     cd novato && make run"
echo "   2. Aventureiro: cd aventureiro && make run"  
echo "   3. Mestre:     cd mestre && make run"
echo ""
echo "📚 DOCUMENTAÇÃO:"
echo "   • README.md principal - Visão geral completa"
echo "   • Cada nível tem seu próprio README.md detalhado"
echo "   • Exemplos de execução em EXEMPLO(S)_EXECUCAO.md"
echo ""
echo "🔧 COMANDOS ÚTEIS:"
echo "   • make help    - Ajuda específica de cada nível"
echo "   • make clean   - Limpar arquivos compilados"
echo "   • make test    - Compilar e executar com detalhes"
echo ""
echo "🎓 PROGRESSÃO RECOMENDADA:"
echo "   Novato → Aventureiro → Mestre"
echo "   (Não pule níveis para melhor aprendizado!)"
echo ""
echo "🎉 Projeto Data Structure Challenger pronto para uso!"
echo "🕵️‍♂️ Boa sorte nas suas investigações, Detective!"
