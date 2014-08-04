<?php
/**
 * @file
 * marketplace_examples.features.inc
 */

/**
 * Implements hook_commerce_custom_offline_payments().
 */
function marketplace_examples_commerce_custom_offline_payments() {
  $items = array(
    'bank_transfer' => array(
      'id' => 'bank_transfer',
      'title' => 'Bank transfer',
      'description' => 'Pay by bank transfer.',
      'information' => '',
      'format' => 'plain_text',
      'status' => 1,
      'checkout' => 1,
      'terminal' => 1,
      'fieldable' => 0,
    ),
    'cash_on_delivery' => array(
      'id' => 'cash_on_delivery',
      'title' => 'Cash on delivery',
      'description' => 'Pay by cash on delivery.',
      'information' => '',
      'format' => 'plain_text',
      'status' => 1,
      'checkout' => 1,
      'terminal' => 1,
      'fieldable' => 0,
    ),
    'cheque' => array(
      'id' => 'cheque',
      'title' => 'Cheque',
      'description' => 'Pay by cheque.',
      'information' => '',
      'format' => 'plain_text',
      'status' => 1,
      'checkout' => 1,
      'terminal' => 1,
      'fieldable' => 0,
    ),
  );
  return $items;
}

/**
 * Implements hook_commerce_flat_rate_default_services().
 */
function marketplace_examples_commerce_flat_rate_default_services() {
  $items = array(
    'free_shipping' => array(
      'name' => 'free_shipping',
      'base' => 'free_shipping',
      'display_title' => 'Free Shipping',
      'description' => '',
      'shipping_method' => 'flat_rate',
      'rules_component' => TRUE,
      'price_component' => 'flat_rate_free_shipping',
      'weight' => 0,
      'callbacks' => array(
        'rate' => 'commerce_flat_rate_service_rate_order',
        'details_form' => 'free_shipping_details_form',
        'details_form_validate' => 'free_shipping_details_form_validate',
        'details_form_submit' => 'free_shipping_details_form_submit',
      ),
      'module' => 'commerce_flat_rate',
      'title' => 'Free Shipping',
      'base_rate' => array(
        'amount' => 0,
        'currency_code' => 'USD',
        'data' => array(),
      ),
      'data' => array(),
      'admin_list' => TRUE,
    ),
    'priority_shipping' => array(
      'name' => 'priority_shipping',
      'base' => 'priority_shipping',
      'display_title' => 'Priority Shipping',
      'description' => '',
      'shipping_method' => 'flat_rate',
      'rules_component' => TRUE,
      'price_component' => 'flat_rate_priority_shipping',
      'weight' => 1,
      'callbacks' => array(
        'rate' => 'commerce_flat_rate_service_rate_order',
        'details_form' => 'priority_shipping_details_form',
        'details_form_validate' => 'priority_shipping_details_form_validate',
        'details_form_submit' => 'priority_shipping_details_form_submit',
      ),
      'module' => 'commerce_flat_rate',
      'title' => 'Priority Shipping',
      'base_rate' => array(
        'amount' => 2000,
        'currency_code' => 'USD',
        'data' => array(),
      ),
      'data' => array(),
      'admin_list' => TRUE,
    ),
    'standard_shipping' => array(
      'name' => 'standard_shipping',
      'base' => 'standard_shipping',
      'display_title' => 'Standard Shipping',
      'description' => '',
      'shipping_method' => 'flat_rate',
      'rules_component' => TRUE,
      'price_component' => 'flat_rate_standard_shipping',
      'weight' => 2,
      'callbacks' => array(
        'rate' => 'commerce_flat_rate_service_rate_order',
        'details_form' => 'standard_shipping_details_form',
        'details_form_validate' => 'standard_shipping_details_form_validate',
        'details_form_submit' => 'standard_shipping_details_form_submit',
      ),
      'module' => 'commerce_flat_rate',
      'title' => 'Standard Shipping',
      'base_rate' => array(
        'amount' => 1000,
        'currency_code' => 'USD',
        'data' => array(),
      ),
      'data' => array(),
      'admin_list' => TRUE,
    ),
  );
  return $items;
}
