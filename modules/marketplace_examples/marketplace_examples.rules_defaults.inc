<?php
/**
 * @file
 * marketplace_examples.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function marketplace_examples_default_rules_configuration() {
  $items = array();
  $items['commerce_shipping_service_free_shipping'] = entity_import('rules_config', '{ "commerce_shipping_service_free_shipping" : {
      "LABEL" : "Rate Free Shipping",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_shipping" ],
      "USES VARIABLES" : { "commerce_order" : { "type" : "commerce_order", "label" : "Order" } },
      "IF" : [
        { "data_is" : {
            "data" : [ "commerce-order:commerce-order-total:amount" ],
            "op" : "\\u003E",
            "value" : "5000"
          }
        }
      ],
      "DO" : [
        { "commerce_shipping_service_rate_order" : {
            "shipping_service_name" : "free_shipping",
            "commerce_order" : [ "commerce-order" ]
          }
        }
      ]
    }
  }');
  $items['commerce_shipping_service_priority_shipping'] = entity_import('rules_config', '{ "commerce_shipping_service_priority_shipping" : {
      "LABEL" : "Rate Priority Shipping",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_shipping" ],
      "USES VARIABLES" : { "commerce_order" : { "type" : "commerce_order", "label" : "Order" } },
      "DO" : [
        { "commerce_shipping_service_rate_order" : {
            "shipping_service_name" : "priority_shipping",
            "commerce_order" : [ "commerce-order" ]
          }
        }
      ]
    }
  }');
  $items['commerce_shipping_service_standard_shipping'] = entity_import('rules_config', '{ "commerce_shipping_service_standard_shipping" : {
      "LABEL" : "Rate Standard Shipping",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "commerce_shipping" ],
      "USES VARIABLES" : { "commerce_order" : { "type" : "commerce_order", "label" : "Order" } },
      "IF" : [
        { "NOT data_is" : {
            "data" : [ "commerce-order:commerce-order-total:amount" ],
            "op" : "\\u003E",
            "value" : "5000"
          }
        }
      ],
      "DO" : [
        { "commerce_shipping_service_rate_order" : {
            "shipping_service_name" : "standard_shipping",
            "commerce_order" : [ "commerce-order" ]
          }
        }
      ]
    }
  }');
  return $items;
}
