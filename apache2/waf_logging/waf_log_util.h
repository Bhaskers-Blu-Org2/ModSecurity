#ifndef _WAF_LOG_UTIL_EXTERNAL_HEADER
#define _WAF_LOG_UTIL_EXTERNAL_HEADER

#define WAF_LOG_UTIL_FAILED -1
#define WAF_LOG_UTIL_SUCCESS 0
#define MODSEC_MODE_DETECT 1
#define MODSEC_MODE_PREVENT 2

// ACTION_ALLOW/ACTION_ALLOW_REQUEST/ACTION_ALLOW_PHASE are defined in the modsecurity.h and copied here
#define ACTION_ALLOW 5
#define ACTION_ALLOW_REQUEST 6
#define ACTION_ALLOW_PHASE 7

#define WAF_RULESET_PREFIX "/RuleSets/"
#define WAF_LOG_UTIL_FILE "waf_json.log"
#define WAF_LOG_UTIL_OPERATION_NAME "ApplicationGatewayFirewall"
#define WAF_LOG_UTIL_CATEGORY "ApplicationGatewayFirewallLog"

// WAF log values passed with request
#define WAF_POLICY_SCOPE "WafPolicyScope"
#define WAF_POLICY_SCOPE_NAME "WafPolicyScopeName"

#define RULE_TYPE_OWASP_CRS "OWASP_CRS"

#define RULE_HASH_SIZE 499

enum ERROR_ENUM {
    none, pcre_limit_error,
};

#ifdef __cplusplus
extern "C" {
#endif
char* generate_json(const char* timestamp, const char* resourceId, const char* operationName, const char* category, const char* instanceId, const char* clientIP, const char* clientPort, const char* requestUri, const char* ruleSetType, const char* ruleSetVersion, const char* ruleId, const char* messages, const int action, const int site, const char* details_messages, const char* details_data, const char* details_file, const char* details_line, const char* hostname, const char* waf_unique_id,
const char* waf_policy_id, const char* waf_policy_scope, const char* waf_policy_scope_name);
void free_json(char* str);
// Returns 0 if succeeded, non-zero code otherwise
int init_appgw_rules_id_hash();
#ifdef __cplusplus
}
#endif

#endif
