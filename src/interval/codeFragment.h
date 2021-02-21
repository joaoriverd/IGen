#ifndef INTERVAL_ARITHMETIC_CODEFRAGMENT_H
#define INTERVAL_ARITHMETIC_CODEFRAGMENT_H

class codeFragment {
public:
    enum eInsertPosition {
        InsertBefore = 0,
        InsertBeforeToken,
        InsertAfter,
        InsertAfterToken,
        Replace
    };

    std::string        code;
    clang::SourceRange range;
    eInsertPosition    position;

    codeFragment() = default;
    codeFragment(std::string c, clang::SourceRange r, eInsertPosition p) : code(c), range(r), position(p) {}

    void replaceCodeFragment(clang::Rewriter& r) const {

        switch (position) {
            case InsertBefore:
                r.InsertTextBefore(range.getBegin(), code);
                break;
            case InsertBeforeToken: {
                /* Little hack. Hope it doesn't break. Use with care. */
                clang::SourceRange sr = range.getBegin().getLocWithOffset(-1);
                std::string c = r.getRewrittenText(sr);
                r.ReplaceText(sr, c + code);
                break;
            }
            case InsertAfter:
                r.InsertTextAfter(range.getEnd(), code);
                break;
            case InsertAfterToken:
                r.InsertTextAfterToken(range.getEnd(), code);
                break;
            case Replace:
                r.ReplaceText(range, code);
                break;
        }
    }
};

#endif //INTERVAL_ARITHMETIC_CODEFRAGMENT_H
