#include "mustache_api.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

static char testfile[] = "sample.html.tpl";


Dict*
simulate_request() {
    Dict *dict = Mstc_dict_new();
    Dict *sub, *subsub;
    Mstc_dict_setValue(dict, "title", "My wonderfull title");
    Mstc_dict_setValue(dict, "name", "jojo");
    Mstc_dict_setValue(dict, "genre", "male");
    Mstc_dict_setValue(dict, "page_link", "<a href=\"https://www.gg.fr\">gg</a>");
    Mstc_dict_setValue(dict, "author", "jojo");
    Mstc_dict_setValue(dict, "url", "http://jojo.fr");

    sub = Mstc_dict_addSectionItem(dict, "pets");
    Mstc_dict_setValue(sub, "name", "gwen");
    Mstc_dict_setValue(sub, "kind", "chien");

    sub = Mstc_dict_addSectionItem(dict, "pets");
    Mstc_dict_setValue(sub, "name", "chuchen");
    Mstc_dict_setValue(sub, "kind", "chat");

    subsub = Mstc_dict_addSectionItem(sub, "nest");
    Mstc_dict_setValue(subsub, "name", "hello nest");

    Mstc_dict_setValue(dict, "footer", "copyrithg jojo");
    Mstc_dict_setValue(dict, "noescape", "<a href=\"#\">jo</a>");
    Mstc_dict_setValue(dict, "escape", "<a href=\"#\">'jo'</a>");

    return dict;
}

int
main(int argc, char **argv) {
    int count;
    if (argc > 1)
        count = atoi(argv[1]);
    else
        count = 1000;

    init_keyhash();

    TemplateStore *store = Mstc_template_create();
    Template *template = Mstc_template_load(store, testfile);

    int i;
    Dict *dict;
    char *output;
    for (i=0; i<count; i++) {
        dict = simulate_request();
        output = Mstc_expand(template, dict);
        Mstc_dict_free(dict);
        free(output);
    }


    /* one more to print out */
    dict = simulate_request();
    output = Mstc_expand(template, dict);
    Mstc_dict_free(ddict

    printf("%s\n",output);
    free(output);

    Mstc_template_free(store);

    return 0;
}
