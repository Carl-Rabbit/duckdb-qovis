#include <string.h>
#include <iostream>

#include "duckdb/planner/logical_operator.hpp"

#include "yyjson.hpp"

using namespace duckdb_yyjson; // NOLINT

namespace duckdb {

class Recorder {
public:
    static void LogMsg(const std::string& msg) {
        std::cout << msg << std::endl;
    }

    static void LogJson(const yyjson_mut_doc *doc) {
        const char *json = yyjson_mut_write(doc, 0, NULL);
        if (json) {
            printf("[RECORD] %s\n", json);
            free((void *)json);
        } else {
            printf("Failed to write JSON\n");
        }
    }

    static void LogStepStart(const std::string& stepName, const std::string& procType, const LogicalOperator &op) {
        yyjson_mut_doc *doc = yyjson_mut_doc_new(NULL);
        yyjson_mut_val *root = yyjson_mut_obj(doc);
        yyjson_mut_doc_set_root(doc, root);
        
        yyjson_mut_obj_add_strcpy(doc, root, "rec_type", "plan");
        yyjson_mut_obj_add_strcpy(doc, root, "step", stepName.c_str());
        yyjson_mut_obj_add_strcpy(doc, root, "proc_type", procType.c_str());
        yyjson_mut_obj_add_strcpy(doc, root, "type", "start");
        yyjson_mut_obj_add_strcpy(doc, root, "plan", op.ToString(ExplainFormat::JSON).c_str());

        LogJson(doc);
        yyjson_mut_doc_free(doc);
    }

    static void LogStepStart(const std::string& stepName, const std::string& procType, const PhysicalOperator &op) {
        yyjson_mut_doc *doc = yyjson_mut_doc_new(NULL);
        yyjson_mut_val *root = yyjson_mut_obj(doc);
        yyjson_mut_doc_set_root(doc, root);
        
        yyjson_mut_obj_add_strcpy(doc, root, "rec_type", "plan");
        yyjson_mut_obj_add_strcpy(doc, root, "step", stepName.c_str());
        yyjson_mut_obj_add_strcpy(doc, root, "proc_type", procType.c_str());
        yyjson_mut_obj_add_strcpy(doc, root, "type", "start");
        yyjson_mut_obj_add_strcpy(doc, root, "plan", op.ToString(ExplainFormat::JSON).c_str());

        LogJson(doc);
        yyjson_mut_doc_free(doc);
    }

    static void LogStepEnd(const std::string& stepName, const std::string& procType, const LogicalOperator &op) {
        yyjson_mut_doc *doc = yyjson_mut_doc_new(NULL);
        yyjson_mut_val *root = yyjson_mut_obj(doc);
        yyjson_mut_doc_set_root(doc, root);
        
        yyjson_mut_obj_add_strcpy(doc, root, "rec_type", "plan");
        yyjson_mut_obj_add_strcpy(doc, root, "step", stepName.c_str());
        yyjson_mut_obj_add_strcpy(doc, root, "proc_type", procType.c_str());
        yyjson_mut_obj_add_strcpy(doc, root, "type", "end");
        yyjson_mut_obj_add_strcpy(doc, root, "plan", op.ToString(ExplainFormat::JSON).c_str());

        LogJson(doc);
        yyjson_mut_doc_free(doc);
    }

    static void LogStepEnd(const std::string& stepName, const std::string& procType, const PhysicalOperator &op) {
        yyjson_mut_doc *doc = yyjson_mut_doc_new(NULL);
        yyjson_mut_val *root = yyjson_mut_obj(doc);
        yyjson_mut_doc_set_root(doc, root);
        
        yyjson_mut_obj_add_strcpy(doc, root, "rec_type", "plan");
        yyjson_mut_obj_add_strcpy(doc, root, "step", stepName.c_str());
        yyjson_mut_obj_add_strcpy(doc, root, "proc_type", procType.c_str());
        yyjson_mut_obj_add_strcpy(doc, root, "type", "end");
        yyjson_mut_obj_add_strcpy(doc, root, "plan", op.ToString(ExplainFormat::JSON).c_str());

        LogJson(doc);
        yyjson_mut_doc_free(doc);
    }
};

}  // namespace duckdb
